/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */

#ifndef TEAMCENTER_SOA_COMMON_XML_LINKEDSTREAMBUFFER_HXX
#define TEAMCENTER_SOA_COMMON_XML_LINKEDSTREAMBUFFER_HXX

#include <iostream>
#include <streambuf>
#include <teamcenter/soa/common/xml/LinkedBuf.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {
               namespace Xml
               {


template <class charT, class traits = std::char_traits<charT> >
class TCSOACOMMON_API LinkedStreamBuffer: public std::basic_streambuf<charT, traits>
{
public:

    typedef charT char_type;
    typedef traits traits_type;
    typedef typename traits_type::int_type int_type;
    typedef typename traits_type::off_type off_type;
    typedef typename traits_type::pos_type pos_type;

    LinkedStreamBuffer();

    ~LinkedStreamBuffer();

    void str( ::std::string& s );

//    SOA_CLASS_NEW_OPERATORS

protected:

    int_type overflow( int_type c=traits::eof() ); //lint -e1735 Default arg value OK

    //The following commented-out method prototypes are not overridden by this template.
    //The trivial behavior implemented for these methods in the parent is sufficient,
    //since LinkedStreamBuffer does not have its own memory storage area.
    //void int_type pbackfail( int_type c=traits::eof() );
    //char_type* pbase() const;
    //void pbump(int n );
    //char_type* pptr() const;
    //pos_type seekoff( off_type off, ios_base::seekdir way, ios:base::openmode which=iosbase::in|ios_base::out );
    //pos_type seekpos( pos_type sp, ios_base::openmode which=ios_base::in|ios_base::out );
    //basic_streambuf<char_type,traits>* setbuf( char_type* s, streamsize n);
    //void setg( char_type* gbegin, char_type* gnext, char_type* gend );
    //void setp( char_type* pbegin, char_type* pend );
    //int sync();

    // Underflow, get a character from the source, advance the read pointer
    int_type uflow();

    // Underflow, get a character from the source, don't advance the read pointer
    int_type underflow();

    // Get n characters from the source
    ::std::streamsize xsgetn( char_type* s, ::std::streamsize n );

    // Put n characters to the source
    ::std::streamsize xsputn ( const char_type* s, ::std::streamsize n );


private:

    ::Teamcenter::Soa::Common::Xml::LinkedBuf source;

};

typedef LinkedStreamBuffer< char,std::char_traits<char> >  LinkedStreamCharBuffer;

}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
