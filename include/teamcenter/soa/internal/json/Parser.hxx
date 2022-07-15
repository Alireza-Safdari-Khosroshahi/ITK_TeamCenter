//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_JSON_PARSER_HXX
#define INCLUDE_TEAMCENTER_JSON_PARSER_HXX

#include <string>
#include <stack>

#include <teamcenter/soa/internal/json/Value.hxx>
#include <teamcenter/soa/internal/json/JSONObject.hxx>
#include <teamcenter/soa/internal/json/JSONArray.hxx>
#include <teamcenter/soa/internal/json/NullValue.hxx>
#include <teamcenter/soa/internal/json/ParsingException.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Json
            {


/**
 * The JSONParser class creates JSONObject or JSONArray objects based on string/text data that conforms 
 * to the JSON syntax rules.
 *
 * <UL>
 * <li> Boolean values are the constant unquoted string of 'true' or 'false'
 * <li> Double (floating point) values are any unquoted decimal value, 3.14 <br>
 *      Scientific notation may be used, values may be proceeded with a '+' or '-' symbol
 * <li> Integer values are any unquoted whole number, 512, values may be proceeded with a '+' or '-' symbol
 * <li> JSONArrays values are enclosed in square brackets, []
 * <li> JSONArrays values are separated by a comma, ','
 * <li> JSONObjects values are enclosed in curly braces, {}
 * <li> JSONObject key/value pairs are separated by a colon, :
 * <li> JSONObject keys are enclosed in double quotes, "keyName"
 * <li> JSONObject key/value pairs are separated by a comma, ','
 * <li> String values are enclosed in double quotes, "The Value"
 *</UL> 
 */
class TCSOACOMMON_API Parser
{
public:

             Parser();
    virtual ~Parser();

    /**
     * Create a JSONObject or JSONArray based on the 
     *
     * @param document The text string to parse
     * @throws ParsingException
     */
    Teamcenter::Soa::Common::AutoPtr<Value> parse( const std::string& document );

protected:


private:
    /**
     * Trim the leading white space
     */
    void trim( );

    /**
     * Validate the current character in the document is the expected token.
     * White space will be discard before validating the token.
     *
     * @param token The expected token in the document
     *
     * @throws ParsingException if the current character does not match the input token
     */
    void validateToken( char token );


    
    /**
     * @returns The type of value of the current text.
     * @throws ParsingException if the text does not match any value type
     */
    Value::ValueType getValueType(  );

    /**
     * @returns The JSONObject key/value pair key
     * @throws ParsingException if the key is not enclosed in double quotes
     */
    std::string getKey(  );

    /**
     * @returns The boolean value from the current text
     */
    bool parseBoolean( );

    /**
     * @returns The integer value from the current text
     */
    int  parseInteger( );
 
    /**
     * @returns The date value from the current text
     */
    Teamcenter::Soa::Common::DateTime parseDate( );

    /**
     * @returns The double value from the current text
     */
    double parseDouble ( );

     /**
     * @returns The JSONObject value from the current text
     * @throws ParsingException if syntax is incorrect for any of the key/value pairs
     */
    Teamcenter::Soa::Common::AutoPtr<JSONObject> parseObject (  );
     
    /**
     * @returns The JSONArray value from the current text
     * @throws ParsingException if syntax is incorrect for any of the element values
     */
    Teamcenter::Soa::Common::AutoPtr<JSONArray>  parseArray  (  );

    /**
     * @returns The NULL value from the current text
     */
    Teamcenter::Soa::Common::AutoPtr<NullValue> parseNull ( );

    /**
     * @returns The string value from the current text
     * @throws ParsingException if the value is not enclosed in double quotes
     */
    std::string parseString (  );
  
    /**
     *
     * @param token The end token of the string value
     * @returns The string value from the current text
     */
    std::string getString ( char token  );
   
    std::string::const_iterator        mCurrentChar;
    std::string::const_iterator        mDocumentEnd;
    int                                mLineInDoc;
    int                                mCharInLine;

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
