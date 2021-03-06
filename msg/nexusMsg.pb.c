/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.2-dev at Fri Dec 26 12:11:26 2014. */

#include "nexusMsg.pb.h"

#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t Header_fields[1] = {
    PB_LAST_FIELD
};

const pb_field_t Twist_fields[5] = {
    PB_FIELD(  1, MESSAGE , OPTIONAL, STATIC  , FIRST, Twist, header, header, &Header_fields),
    PB_FIELD(  2, FLOAT   , REQUIRED, STATIC  , OTHER, Twist, velX, header, 0),
    PB_FIELD(  3, FLOAT   , REQUIRED, STATIC  , OTHER, Twist, velY, velX, 0),
    PB_FIELD(  4, FLOAT   , REQUIRED, STATIC  , OTHER, Twist, rotZ, velY, 0),
    PB_LAST_FIELD
};

const pb_field_t NexusMsg_fields[4] = {
    PB_FIELD(  1, MESSAGE , REQUIRED, STATIC  , FIRST, NexusMsg, header, header, &Header_fields),
    PB_FIELD(  2, MESSAGE , OPTIONAL, STATIC  , OTHER, NexusMsg, cmdVel, header, &Twist_fields),
    PB_FIELD(  3, MESSAGE , OPTIONAL, STATIC  , OTHER, NexusMsg, actVel, cmdVel, &Twist_fields),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(Twist, header) < 65536 && pb_membersize(NexusMsg, header) < 65536 && pb_membersize(NexusMsg, cmdVel) < 65536 && pb_membersize(NexusMsg, actVel) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_Header_Twist_NexusMsg)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(Twist, header) < 256 && pb_membersize(NexusMsg, header) < 256 && pb_membersize(NexusMsg, cmdVel) < 256 && pb_membersize(NexusMsg, actVel) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_Header_Twist_NexusMsg)
#endif


