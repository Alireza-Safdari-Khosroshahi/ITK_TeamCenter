//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
#ifndef INCLUDE_TEAMCENTER_JSON_VALUE_HXX
#define INCLUDE_TEAMCENTER_JSON_VALUE_HXX

#include <vector>
#include <iostream>
#include <string>

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
class JSONArray;
/**
 * Base class for a valid JSON value.
 * A Value may be a  {@link Boolean}, {@link Double} , {@link Integer}, 
 * {@link JSONArray}, {@link JSONObject} or {@link String}
 */
class TCSOACOMMON_API Value
{
public:

    enum ValueType
    {
        UndeterminedValueType,
        BooleanValueType,
        DoubleValueType,
        IntegerValueType,
        JSONArrayValueType,
        JSONObjectValueType,
        NullValueType,
        StringValueType,
        DateValueType       // Not an official JSON type
    };

    /**
     * Set the size of tabs used in the serialization methods of JSONObject or JSONArray.
     * Default tab size is 2.
     *
     * @param size The number of spaces in a tab
     */
    static void setTabSize( size_t size );

    Value();
    virtual ~Value();

    // AutoPtr methods
    void ref();
    void unref();




   /**
    * @return True if this object has no elements or keys.
    */
    virtual bool      isEmpty() const=0;

    /**
    * @return The number of properties in an object or the size of the array.
    */
    virtual size_t    size()    const=0;

    /**
     * @return The type of this Value.
     */
    virtual ValueType getType() const=0;


protected:
    friend class JSONObject;
    friend class JSONArray;

    virtual void serialize( int level, std::ostream& document ) const=0;
    static std::string  getPadding( int level );

private:
    static size_t sTabSize;

    int mRefCount;
   
};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
