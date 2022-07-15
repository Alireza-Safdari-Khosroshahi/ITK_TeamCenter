// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_COMMON_XML_UTF8STRING_HXX
#define TEAMCENTER_SOA_COMMON_XML_UTF8STRING_HXX

#include <string>
#include <stdint.h>
#include <icu/common/unicode/ucnv.h>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>
#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            namespace Xml
            {
                class Utf8String;
            }
        }
    }
}



class TCSOACOMMON_API Teamcenter::Soa::Common::Xml::Utf8String
{
public:
    /**
     * Encode a string to UTF-8
     * @param localeString  Source string
     * @param encodedString The target UTF-8 encocoded string
     * @param encoding      Source string would be in this encoding. For eg. "UTF8" 
     *                      could be an example of encoding value.The encoding value
     *                      is case-insensitive input that ignores the delimiters '-',
     *                      '_', and ' ' dash, underscore, and space). The names "UTF8", 
     *                      "utf-8" and "Utf 8" are all equivalent. A "" value would mean
     *                      source string is in local code page
     *
     * @exception An InternalServerException is thrown if errors are encountered.
     */
    static void encode( const std::string& localeString, std::string& encodedString, const std::string& encoding="" );
    static std::string encode( const std::string& localeString, const std::string& encoding="" );

    /**
     * Decode a string from UTF-8 
     * @param utf8String    Source string encoded with UTF-8
     * @param decodedString The target decoded string
     * @param encoding      Output string encoding. "UTF8" could
     *                      be an example of encoding value.
     *                      The encoding value is case-insensitive input that ignores
     *                      the delimiters '-', '_', and ' ' (dash, underscore, and space).
     *                      The names "UTF8", "utf-8" and "Utf 8" are all equivalent.
     *
     * @exception An InternalServerException is thrown if errors are encountered.
     */
    static void decode( const std::string& utf8String,  std::string& decodedString, const std::string& encoding="");
    static std::string decode( const std::string& utf8String, const std::string& encoding="");

    /**
     * Convert a string from Unicode to some other encoding 
     * @param unicodeStr    Source string encoded with UTF-8
     * @param length        No of input Unicode characters 
     * @param encoding      Output string encoding. "UTF8" could
     *                      be an example of encoding value.
     *                      The encoding value is case-insensitive input that ignores
     *                      the delimiters '-', '_', and ' ' (dash, underscore, and space).
     *                      The names "UTF8", "utf-8" and "Utf 8" are all equivalent.
     *
     * @return A string encoded using given encoding
     * @exception An InternalServerException is thrown if errors are encountered.
     */
    static std::string UnicodeToEncoding( const UChar* unicodeStr, int length, const std::string& encoding );


    SOA_CLASS_NEW_OPERATORS

private:
    explicit Utf8String( bool encode, size_t size, const std::string& encoding = "" );
    ~Utf8String();

    // Don't allow default and copy constructors
    Utf8String();
    Utf8String( const Utf8String& right);
    Utf8String& operator = ( const Utf8String& right);

    static void handleError( const UConverter *converter,  UErrorCode cStatus, bool toUnicode );
    
    size_t uniBufSize;
    size_t endBufSize;
    UChar* uniBuffer;
    char*  endBuffer;
    static std::map<std::string, UConverter*>    localeConverters;
    static UConverter *utfConverter;
    static Teamcenter::Soa::Internal::Common::Mutex    mutex;

};

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
