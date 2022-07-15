//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2013
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.





#ifndef TEAMCENTER_SOA_SERVER_PROPERTY_HXX
#define TEAMCENTER_SOA_SERVER_PROPERTY_HXX

#include <string>
#include <base_utils/DateTime.hxx>
#include <metaframework/BusinessObjectRef.hxx>

#include <teamcenter/soa/common/DateTime.hxx> // Need?
#include <teamcenter/soa/server/SoaServerExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Server
         {


class TCSOASERVER_API Property
{
public:

    /**
     * Utility function to parse a string argument as a boolean.<br>
     * A true value is returned represents if the input string  is "true" or "1".
     * False is returned for all other string values and null strings.
     * <br><br>
     * In general the parseXXX methods of the Property class are to be used with the
     * corresponding toXXXString methods (i.e. parseBoolean and toBooleanString) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the service implementation will use
     * the Property.toStringXXX methods to convert the data type to a string, and the calling
     * client code is responsible for using the appropriate Property.parseXXX method to convert
     * it back to the desired data type.
     *
     * @param s     The String containing the boolean representation to be parsed .
     * @return      The boolean represented by the string argument
     */
    static bool parseBoolean( const std::string& s );
    static logical parseLogical( const std::string& s );
    /**
     * Utility function used to convert a boolean to a string.<br>
     * If the specified boolean is true, then the string "1" will be returned.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param b     The boolean to be converted.
     * @return      The string representation of the specified boolean.
     */
    static std::string toBooleanString( bool b );
    static std::string toLogicalString( logical l );


    /**
     * Utility function to parse a string argument as a char.<br>
     * The char returned is based on the numeric value of the
     * input string (0 .. 255). If the input string is null or empty the 0x0 char will be returned.
     * <br><br>
     * In general the parseXXX methods of the Property class are to be used with the
     * corresponding toXXXString methods (i.e. parseBoolean and toBooleanString) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the service implementation will use
     * the Property.toStringXXX methods to convert the data type to a string, and the calling
     * client code is responsible for using the appropriate Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The String containing the char representation to be parsed .
     * @return      The char represented by the string argument
     */
     static char parseChar( const std::string& s );
   /**
     * Utility function used to convert a char to a string<br>
     * A string representing the numeric (0..255) value of the char is returned.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param c     The char to be converted.
     * @return      The string representation of the specified char.
     */
    static std::string toCharString( char c );

    /**
     * Utility function to parse a string argument as a DateTime.<br>
     * The input string must be in the format 'yyyy-MM-dd'T'HH:mm:ssZ'.
     * <br><br>
     * In general the parseXXX methods of the Property class are to be used with the
     * corresponding toXXXString methods (i.e. parseBoolean and toBooleanString) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the service implementation will use
     * the Property.toStringXXX methods to convert the data type to a string, and the calling
     * client code is responsible for using the appropriate Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The String containing the DateTime representation to be parsed .
     * @return      The DateTime represented by the string argument
     */
    static Teamcenter::DateTime parseDate( const std::string& s);
    /**
     * Utility function used to convert a DateTime to a string.<br>
     * A string with the format 'yyyy-MM-dd'T'HH:mm:ssZ' is returned.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param d     The DateTime to be converted.
     * @return      The string representation of the specified DateTime.
     */
    static std::string toDateString( const Teamcenter::DateTime& d );


    /**
     * Utility function to parse a string argument as a double.<br>
     * This method assumes the input string will have decimal point (3.14) vs. a
     * decimal comma (3,14) regardless of locale. Standard or Scientific notations are
     * accepted as input.
     * <br><br>
     * In general the parseXXX methods of the Property class are to be used with the
     * corresponding toXXXString methods (i.e. parseBoolean and toBooleanString) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the service implementation will use
     * the Property.toStringXXX methods to convert the data type to a string, and the calling
     * client code is responsible for using the appropriate Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The String containing the double representation to be parsed .
     * @return      The double represented by the string argument
     */
    static double parseDouble( const std::string& s );
    /**
     * Utility function used to convert a double to a string.<br>
     * Regardless of locale this method will return a string with a decimal point (3.14)
     * vs. a decimal comma (3,14). The string may also be returned as Standard or Scientific notation
     * depending on the precision of the input value
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param d     The double to be converted.
     * @return      The string representation of the specified double.
     */
    static std::string toDoubleString( double d );


   /**
     * Utility function to parse a string argument as a float.<br>
     * This method assumes the input string will have decimal point (3.14) vs. a
     * decimal comma (3,14) regardless of locale. Standard or Scientific notations are
     * accepted as input.
     * <br><br>
     * In general the parseXXX methods of the Property class are to be used with the
     * corresponding toXXXString methods (i.e. parseBoolean and toBooleanString) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the service implementation will use
     * the Property.toStringXXX methods to convert the data type to a string, and the calling
     * client code is responsible for using the appropriate Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The String containing the float representation to be parsed .
     * @return      The float represented by the string argument
     */
    static float parseFloat( const std::string& s );
     /**
     * Utility function used to convert a float to a string.<br>
     * Regardless of locale this method will return a string with a decimal point (3.14)
     * vs. a decimal comma (3,14). The string may also be returned as Standard or Scientific notation
     * depending on the precision of the input value
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param f     The float to be converted.
     * @return      The string representation of the specified float.
     */
    static std::string toFloatString( float f );


   /**
     * Utility function to parse a string argument as an integer.
     * <br><br>
     * In general the parseXXX methods of the Property class are to be used with the
     * corresponding toXXXString methods (i.e. parseBoolean and toBooleanString) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the service implementation will use
     * the Property.toStringXXX methods to convert the data type to a string, and the calling
     * client code is responsible for using the appropriate Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The String containing the int representation to be parsed .
     * @return      The int represented by the string argument
     */
    static int parseInt( const std::string& s );
    /**
     * Utility function used to convert an integer to a string.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param i     The int to be converted.
     * @return      The string representation of the specified int.
     */
    static std::string toIntString( int i );

    /**
     * Utility function to parse a string argument as a short.
     * <br><br>
     * In general the parseXXX methods of the Property class are to be used with the
     * corresponding toXXXString methods (i.e. parseBoolean and toBooleanString) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the service implementation will use
     * the Property.toStringXXX methods to convert the data type to a string, and the calling
     * client code is responsible for using the appropriate Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The String containing the short representation to be parsed .
     * @return      The short represented by the string argument
     */
   static short parseShort( const std::string& s );
     /**
     * Utility function used to convert a short to a string.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The short to be converted.
     * @return      The string representation of the specified short.
     */
    static std::string toShortString( short s );

  /**
     * Utility function used to convert a ModelObject to a string.
     * This method does not serialize the entire object (property values .etc), it simply
     * returns the UID.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param s     The ModelObject to be converted.
     * @return      The string representation of the specified ModelObject.
     *
     */
    static BusinessObjectRef<Teamcenter::BusinessObject> parseModel( const std::string& s );

  /**
     * Utility function used to convert a ModelObject to a string.
     * This method does not serialize the entire object (property values .etc), it simply
     * returns the UID.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many service operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param m     The ModelObject to be converted.
     * @return      The string representation of the specified ModelObject.
     *
     */
    static std::string toModelString( const BusinessObjectRef<Teamcenter::BusinessObject> m );


};
}}}

#include <teamcenter/soa/server/SoaServerUndef.h>

#endif

