//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_JSON_JSONOBJECT_HXX
#define INCLUDE_TEAMCENTER_JSON_JSONOBJECT_HXX

#include <string>
#include <map>

#include <teamcenter/soa/internal/json/Value.hxx>
#include <teamcenter/soa/internal/json/NullValue.hxx>
#include <teamcenter/soa/internal/json/KeyNotFoundException.hxx>
#include <teamcenter/soa/internal/json/InvalidTypeException.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/DateTime.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Json
            {

class JSONArray;
class Null;


/**
 * A JSONObject is an unordered collection of name/value pairs. 
 * Its external form is a string wrapped in curly braces with colons between the names and values, 
 * and commas between the values and names. The internal form is an object having get methods for 
 * accessing the values by name, and accumulate methods for adding or replacing values by name. 
 * The values can be any of these types: Value, Boolean, JSONArray, JSONObject, Integer, Double, or String.
 */
class TCSOACOMMON_API JSONObject : public Teamcenter::Soa::Internal::Json::Value
{
public:

    JSONObject( );
    virtual ~JSONObject();

    virtual bool      isEmpty() const;
    virtual size_t    size()    const;
    virtual ValueType getType() const;

    /**
     * Add a key/boolean pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, bool   value );

    /**
     * Add a key/DateTime pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, const Teamcenter::Soa::Common::DateTime& value );


    /**
     * Add a key/double pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, double value );

    /**
     * Add a key/integer pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, int    value );

    /**
     * Add a key/JSONArray pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONArray>  value );

    /**
     * Add a key/JSONObject pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> value );

    /**
     * Add a key/Value pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::NullValue> value );

    /**
     * Add a key/string pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, const std::string& value );

    /**
     * Add a key/string pair in the JSONObject.
     *
     * @param key   The pair name
     * @param value The pair value
     */
    void accumulate( const std::string& key, const char* value );


    /**
     * @param key The name of the disired pair.
     * @returns True if the named key is in the JSONObject.
     */
    bool      containsKey ( const std::string& key ) const;

    /**
     * @returns A list of all Key in this JSONObject.
     */
    std::vector<std::string> getKeys() const;

    /**
     * @param key The name of the disired pair.
     * @returns The type of the named pair.
     */
    Value::ValueType getValueType( const std::string& key ) const;

   /**
     * @param key The name of the disired pair.
     * @returns true if the value at the given index is NULL
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     */
    bool isNull( const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the named boolean pair.
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     * @throws InvalidTypeException if the named key is not a boolean
     */
    bool getBoolean   (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the named date pair.
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     * @throws InvalidTypeException if the named key is not a date
     */
    Teamcenter::Soa::Common::DateTime getDate    (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the named double pair.
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     * @throws InvalidTypeException if the named key is not a double
     */
    double getDouble    (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the named integer pair.
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     * @throws InvalidTypeException if the named key is not a integer
     */
    int getInteger   (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the named JSONArray pair.
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     * @throws InvalidTypeException if the named key is not a JSONArray
     */
    Teamcenter::Soa::Common::AutoPtr<JSONArray>  getJSONArray (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the named JSONObject pair.
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     * @throws InvalidTypeException if the named key is not a JSONObject
     */
    Teamcenter::Soa::Common::AutoPtr<JSONObject> getJSONObject(  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the named string pair.
     * @throws KeyNotFoundException if the named key is not in the JSONObject
     * @throws InvalidTypeException if the named key is not a string
     */
    const std::string& getString    (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the key as std::string.
     */
    std::string getKeyAsString   (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the key as boolean.
     */
    bool getKeyAsBoolean   (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the key as int.
     */
    int getKeyAsInteger   (  const std::string& key ) const;

    /**
     * @param key The name of the disired pair.
     * @returns The value of the key as double.
     */
    double getKeyAsDouble   (  const std::string& key ) const;

    void  serialize(  std::ostream& document ) const;

protected:
    virtual void  serialize( int level, std::ostream& document ) const;

private:
    std::map<std::string,Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::Value> > mJSONObjValues;

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
