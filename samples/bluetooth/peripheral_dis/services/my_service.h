#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr.h>
#include <soc.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>

#define MY_SERVICE_UUID 0xb8, 0x45, 0xef, 0x56, 0x43, 0xe0, 0xa3, 0x80, 0x75, 0x41, 0x60, 0xb1, 0xf1, 0xf4, 0x6f, 0xae

/*TX_CHARACTERISTIC_UUID*/
#define SEND_CHARACTERISTIC  0xe5, 0xb7, 0x10, 0x8a, 0xf5, 0x3b, 0xf9, 0x91, 0x9e, 0x4d, 0x61, 0x1a, 0x7d, 0x80, 0x44, 0x92

#define RECEIVE_CHARACTERISTIC 0x11, 0xAA, 0x20, 0x11, 0x92, 0xE7, 0x43, 0x5A, 0xAA, 0xE9, 0x94, 0x43, 0x35, 0x6A, 0xD4, 0xD3

#define BT_LE_ADV_CONN2 BT_LE_ADV_PARAM(BT_LE_ADV_OPT_CONNECTABLE, \
				       BT_GAP_ADV_FAST_INT_MIN_2*5, \
				       BT_GAP_ADV_FAST_INT_MAX_2*10, NULL)
/** @brief Callback type for when new data is received. */
typedef void (*data_rx_cb_t)(u8_t *data, u8_t length);

/** @brief Callback struct used by the my_service Service. */
struct my_service_cb 
{
	/** Data received callback. */
	data_rx_cb_t    data_rx_cb;
};


/** @brief Callback type for data received. */
typedef void (*climb_received_cb_t)(struct bt_conn *conn,
				  const u8_t *const data, u16_t len);

typedef void (*notif_func)();

int my_service_init(climb_received_cb_t rec_cb, notif_func notif_func);

void my_service_send(struct bt_conn *conn, const u8_t *data, uint16_t len);
