/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.2-dev at Fri Dec 26 12:11:26 2014. */

#ifndef PB_NEXUSMSG_PB_H_INCLUDED
#define PB_NEXUSMSG_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _MessageType {
    MessageType_TWIST = 1,
    MessageType_POSITION = 2,
    MessageType_ODOM = 3
} MessageType;

/* Struct definitions */
typedef struct _Header {
    uint8_t dummy_field;
} Header;

typedef struct _Twist {
    bool has_header;
    Header header;
    float velX;
    float velY;
    float rotZ;
} Twist;

typedef struct _NexusMsg {
    Header header;
    bool has_cmdVel;
    Twist cmdVel;
    bool has_actVel;
    Twist actVel;
} NexusMsg;

/* Default values for struct fields */

/* Initializer values for message structs */
#define Header_init_default                      {0}
#define Twist_init_default                       {false, Header_init_default, 0, 0, 0}
#define NexusMsg_init_default                    {Header_init_default, false, Twist_init_default, false, Twist_init_default}
#define Header_init_zero                         {0}
#define Twist_init_zero                          {false, Header_init_zero, 0, 0, 0}
#define NexusMsg_init_zero                       {Header_init_zero, false, Twist_init_zero, false, Twist_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define Twist_header_tag                         1
#define Twist_velX_tag                           2
#define Twist_velY_tag                           3
#define Twist_rotZ_tag                           4
#define NexusMsg_header_tag                      1
#define NexusMsg_cmdVel_tag                      2
#define NexusMsg_actVel_tag                      3

/* Struct field encoding specification for nanopb */
extern const pb_field_t Header_fields[1];
extern const pb_field_t Twist_fields[5];
extern const pb_field_t NexusMsg_fields[4];

/* Maximum encoded size of messages (where known) */
#define Header_size                              0
#define Twist_size                               17
#define NexusMsg_size                            40

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif