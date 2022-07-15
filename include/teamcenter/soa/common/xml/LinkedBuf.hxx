// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2010.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 
/** 
    @file 
 
    This is a non-fragmenting, non-contiguous high-performance
    byte buffer with read-write APIs.
    It is not thread safe.
*/


#ifndef TEAMCENTER_SOA_COMMON_XML_LINKEDBUF_H
#define TEAMCENTER_SOA_COMMON_XML_LINKEDBUF_H

#include <string>

#include <teamcenter/soa/common/SoaCommonExports.h>

/* next structure intended to be created via calloc */
typedef struct baselinkstruct 
{
   size_t                 alloc_size;  /* size in bytes of buffer */
   size_t                 r_cursor;    /* read cursor of buffer   */ 
   size_t                 w_cursor;    /* write cursor of buffer  */
   char                  *buffer;      /* malloc'd buffer         */ 
   struct baselinkstruct *next;        /* pointer to next link_ptr */ 
} buffer_link_t, *link_ptr;


typedef struct 
{
    link_ptr  head;                /* link to read from */ 
    link_ptr  tail;                /* link to write to  */
    void     *magic;               /* defensive programming */ 
} all_buffers_t, *Buffer_ptr;


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {
               namespace Xml
               {
class TCSOACOMMON_API LinkedBuf
{
public:
    LinkedBuf();

    ~LinkedBuf();

    int putn( const char *str, const int len );
    int getn( char into[], const int len );
    int peekn( char into[], const int len );
    void str( std::string& s );

private:
    Buffer_ptr m_buffer_ptr;
}
;
}}}}  // namespace


#include <teamcenter/soa/common/SoaCommonUndef.h>

/* TEAMCENTER_LINKEDBUF_H */
#endif

