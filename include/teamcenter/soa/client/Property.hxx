// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.




#ifndef TEAMCENTER_SOA_CLIENT_PROPERTY_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTY_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/client/PropertyDescription.hxx>
#include <teamcenter/soa/client/ErrorStack.hxx>

#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
class ModelObject;
class ErrorStack;

typedef std::vector<char> CharVector;
typedef std::vector<double> DoubleVector;
typedef std::vector<float> FloatVector;
typedef std::vector<int> IntVector;
typedef std::vector<bool> BoolVector;
typedef std::vector<short> ShortVector;
typedef std::vector<std::string> StringVector;
typedef std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> > ModelObjectVector;

typedef std::vector<ErrorStack> ErrorStackVector;
class TCSOACLIENTMNGD_API Property
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
     *
     * @param s     The String containing the boolean representation to be parsed.
     * @return      The boolean represented by the string argument
     */
    static bool parseBoolean( const std::string& s );
    /**
     * Utility function used to convert a boolean to a string.<br>
     * If the specified boolean is true, then the string "1" will be returned.
     * <br><br>
     * In general the toXXXString methods of the Property class are to be used with the
     * corresponding parseXXXX methods (i.e. toBooleanString and parseBoolean) to
     * serialize and deserialize the different Property data types (Boolean, Float, Date .etc)
     * to and from a string. Many serivce operations will expose a string argument to
     * represent any Property data type, in these cases the calling client is responsible
     * to use the appropriate Property.toXXXString method to convert the source data type to a string,
     * and the service implementation  will use the corresponding Property.parseXXX method to convert
     * it back to the desired data type.
     *
     *
     * @param b     The boolean to be converted.
     * @return      The string representation of the specified boolean.
     */
    static std::string toBooleanString( bool b );


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
    static Teamcenter::Soa::Common::DateTime parseDate( const std::string& s);
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
    static std::string toDateString( const Teamcenter::Soa::Common::DateTime& d );


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
     * @param m     The ModelObject to be converted.
     * @return      The string representation of the specified ModelObject.
     *
     */
    static std::string toModelObjectString(const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> m );


    /**
     * This method will use the appropriate toXXXString functions to convert the
     * value of this property to a local neutral string. This method should be used for
     * Properties that have a single value. For multi-valued properties use the
     * toNeutralStrings method.
     *
     *
     * @return  The neutral string
     */
    std::string toNeutralString(  ) const;

    /**
     * This method will use the appropriate toXXXString functions to convert the
     * values of this property to a local neutral string. This method should be used for
     * Properties that are an array of values. For single valued properties use the
     * toNeutralString method.
     *
     *
     * @return  The neutral strings
     */
    std::vector<std::string> toNeutralStrings(  ) const;


   /**
     *
     * @return The property display value
     *
     * @deprecated As of 8.2, use getDisplayableValue or getDisplayableValues.
     *             This method does not distinguish between a property that has one or multiple values.
     *             Display value for multiple valued properties are returned as a comma (,) separated list.
     */
#ifdef WNT
__declspec(deprecated("As of 8.2, use getDisplayableValue or getDisplayableValues. This method does not distinguish between a property that has one or multiple values.  Display value for multiple valued properties are returned as a comma (,) separated list."))
#endif
    virtual std::string           getDisplayValue() const = 0;



    /**
     * Gets the property's display value. If this property has multiple values, this method
     * will return the first display value. Use the getDisplayableValues for properties that have
     * multiple values.
     *
     * @return The property's display value.
     */
    virtual std::string               getDisplayableValue() const = 0;

    /**
     * Gets the property's display values.
     *
     * @return The property's display value.
     */
    virtual std::vector<std::string>         getDisplayableValues() const = 0;



    virtual Teamcenter::Soa::Client::PropertyDescription*  getPropertyDescription() const = 0;
    virtual bool    isNull() const = 0;
    virtual bool    isModifiable() const =0;

    virtual char getCharValue() const = 0;
    virtual const Teamcenter::Soa::Common::DateTime& getDateTimeValue() const = 0;
    virtual double getDoubleValue() const = 0;
    virtual float getFloatValue() const = 0;
    virtual int getIntValue() const = 0;
    virtual bool getBoolValue() const = 0;
    virtual short getShortValue() const = 0;
    virtual const std::string& getStringValue() const = 0;
    virtual Teamcenter::Soa::Common::AutoPtr<ModelObject> getModelObjectValue() const = 0;


    virtual const CharVector& getCharArrayValue() const = 0;
    virtual const Teamcenter::Soa::Common::DateTimeVector&  getDateTimeArrayValue() const = 0;
    virtual const DoubleVector& getDoubleArrayValue() const = 0;
    virtual const FloatVector& getFloatArrayValue() const = 0;
    virtual const IntVector& getIntArrayValue() const = 0;
    virtual const BoolVector& getBoolArrayValue() const = 0;
    virtual const ShortVector& getShortArrayValue() const = 0;
    virtual const StringVector& getStringArrayValue() const = 0;
    virtual const ModelObjectVector& getModelObjectArrayValue() const = 0;


    SOA_CLASS_NEW_OPERATORS

protected:
    virtual ~Property() = 0;

};
}}} //end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

