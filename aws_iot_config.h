#ifndef AWS_IOT_CONFIG_H_
#define AWS_IOT_CONFIG_H_

// Get from console
#define AWS_IOT_MQTT_HOST              "your-aws-iot-endpoint" ///< Customer specific MQTT HOST. The same will be used for Thing Shadow
#define AWS_IOT_MQTT_PORT              8883 ///< default port for MQTT/S
#define AWS_IOT_MQTT_CLIENT_ID         "your-client-id" ///< MQTT client ID should be unique for every device
#define AWS_IOT_MY_THING_NAME          "your-thing-name" ///< Thing Name of the Shadow this device is associated with

// Get from console
#define AWS_IOT_ROOT_CA_FILENAME       "path/to/rootCA.pem" ///< Root CA file name
#define AWS_IOT_CERTIFICATE_FILENAME   "path/to/certificate.pem.crt" ///< device signed certificate file name
#define AWS_IOT_PRIVATE_KEY_FILENAME   "path/to/private.pem.key" ///< Device private key filename

// MQTT PubSub
#define AWS_IOT_MQTT_TX_BUF_LEN 512 ///< Buffer size for MQTT TX
#define AWS_IOT_MQTT_RX_BUF_LEN 512 ///< Buffer size for MQTT RX
#define AWS_IOT_MQTT_NUM_SUBSCRIBE_HANDLERS 5 ///< Maximum number of topic filters the MQTT client can handle at any time

// Shadow specific configs
#define SHADOW_MAX_SIZE_OF_RX_BUFFER 512 ///< Maximum size of the SHADOW RX buffer
#define MAX_SIZE_OF_UNIQUE_CLIENT_ID_BYTES 80 ///< Maximum size of the unique client id
#define MAX_SIZE_CLIENT_ID_WITH_SEQUENCE MAX_SIZE_OF_UNIQUE_CLIENT_ID_BYTES + 10 ///< Maximum size of the client id with sequence
#define MAX_SIZE_CLIENT_TOKEN_CLIENT_SEQUENCE MAX_SIZE_CLIENT_ID_WITH_SEQUENCE + 20 ///< Maximum size of the client token with sequence
#define MAX_ACKS_TO_COMEIN_AT_ANY_GIVEN_TIME 10 ///< Maximum number of ACKS that can be received at any time
#define MAX_THINGNAME_HANDLED_AT_ANY_GIVEN_TIME 10 ///< Maximum number of Thing Names that can be handled at any time
#define MAX_JSON_TOKEN_EXPECTED 120 ///< Maximum number of JSON tokens expected in the JSON document
#define MAX_SHADOW_TOPIC_LENGTH_WITHOUT_THINGNAME 60 ///< Maximum size of the shadow topic without the Thing Name
#define MAX_SIZE_OF_THING_NAME 20 ///< Maximum size of the Thing Name
#define MAX_SHADOW_TOPIC_LENGTH_BYTES MAX_SHADOW_TOPIC_LENGTH_WITHOUT_THINGNAME + MAX_SIZE_OF_THING_NAME ///< Maximum size of the shadow topic with the Thing Name

// Auto Reconnect specific config
#define AWS_IOT_MQTT_MIN_RECONNECT_WAIT_INTERVAL 1000 ///< Minimum time before the client attempts to reconnect in milliseconds
#define AWS_IOT_MQTT_MAX_RECONNECT_WAIT_INTERVAL 128000 ///< Maximum time before the client attempts to reconnect in milliseconds

#endif /* AWS_IOT_CONFIG_H_ */
