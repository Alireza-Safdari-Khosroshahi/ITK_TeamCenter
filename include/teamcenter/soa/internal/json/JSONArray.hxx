//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
#ifndef INCLUDE_TEAMCENTER_JSON_JSONARRAY_HXX
#define INCLUDE_TEAMCENTER_JSON_JSONARRAY_HXX

#include <string>
#include <vector>
#include <map>

#include <teamcenter/soa/internal/json/Value.hxx>
#include <teamcenter/soa/internal/json/NullValue.hxx>
#include <teamcenter/soa/internal/json/InvalidTypeException.hxx>
#include <teamcenter/soa/internal/json/IndexOutOfRangeException.hxx>
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

class JSONObject;
class Null;
/**
 * A JSONArray is an ordered sequence of values. 
 * Its external form is a string wrapped in square backets with commas separating the values.
 * The internal form is an object having get methods for accessing the values by index, 
 * and add methods for adding values. 
 * The values can be any of these types: Boolean, JSONArray, JSONObject, Integer, Double, or String.
 */
class TCSOACOMMON_API JSONArray : public Teamcenter::Soa::Internal::Json::Value
{
public:

    JSONArray( );
    virtual ~JSONArray();

    virtual bool      isEmpty() const;
    virtual size_t    size()    const;
    virtual ValueType getType() const;
         

    /**
     * Add a boolean value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of boolean type.
     */
    void add( bool   value );

    /**
     * Add a date value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of date type.
     */
    void add( const Teamcenter::Soa::Common::DateTime& value );

    /**
     * Add a double value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of double type.
     */
    void add( double value );

    /**
     * Add a integer value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of integer type.
     */
    void add( int    value );

    /**
     * Add a JSONArray value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of JSONArray type.
     */
    void add( Teamcenter::Soa::Common::AutoPtr<JSONArray>  value );

    /**
     * Add a JSONObject value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of JSONObject type.
     */
    void add( Teamcenter::Soa::Common::AutoPtr<JSONObject> value );
 
    /**
     * Add a Value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of match in the input type.
     */
    void add( Teamcenter::Soa::Common::AutoPtr<NullValue> value );
 
    /**
     * Add a string value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of string type.
     */
    void add( const std::string& value );

   /**
     * Add a string value to the JSONArray.
     *
     * @param value The value
     * @throws InvalidTypeException if existing elements in this array are not of string type.
     */
    void add( const char* value );

    /**
     * @param index The 0 based index of the element in the JSONArray.
     * @returns The type of value in the specified index in this JSONArray.
     */
    Value::ValueType getValueType( size_t index ) const;


    /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns true if the value at the given index is NULL
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    bool isNull( size_t index ) const;

   /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The boolean value.
     * @throws InvalidTypeException     if the elements in this JSONArray are not booleans
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    bool getBoolean   (  size_t index ) const;

   /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The date value.
     * @throws InvalidTypeException     if the elements in this JSONArray are not dates
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    Teamcenter::Soa::Common::DateTime getDate    (  size_t index ) const;

  /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The double value.
     * @throws InvalidTypeException     if the elements in this JSONArray are not doubles
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    double getDouble    (  size_t index ) const;

   /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The integer value.
     * @throws InvalidTypeException     if the elements in this JSONArray are not integers
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    int getInteger   (  size_t index ) const;
 
   /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The JSONArrray value.
     * @throws InvalidTypeException     if the elements in this JSONArray are not JSONArrrays
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    Teamcenter::Soa::Common::AutoPtr<JSONArray>  getJSONArray (  size_t index ) const;

   /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The JSONObject value.
     * @throws InvalidTypeException     if the elements in this JSONArray are not JSONObjects
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    Teamcenter::Soa::Common::AutoPtr<JSONObject> getJSONObject(  size_t index ) const;

    /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The JSON value.
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::Value> getValue(  size_t index ) const;



    /**
     * @param index The 0 based index of the desired element in the JSONArray.
     * @returns The string value.
     * @throws InvalidTypeException     if the elements in this JSONArray are not strings
     * @throws IndexOutOfRangeException if the index is larger than the number of elements in the JSONArray
     */
    const std::string& getString    (  size_t index ) const;
        
    void      serialize( std::ostream& document ) const;

protected:
    virtual void      serialize( int level, std::ostream& document ) const;

private:

    std::string getInvalidTypeMessage( size_t index )const;
    std::string getOutOfRangeMessage( size_t index ) const;

    std::vector<ValueType> mValueTypes;
    std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::Value> > mJSONObjValues;

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
