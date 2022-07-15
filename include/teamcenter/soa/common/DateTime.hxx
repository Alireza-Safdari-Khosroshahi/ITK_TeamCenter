/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */

#ifndef TEAMCENTER_SOA_COMMON_DATETIME_HXX
#define TEAMCENTER_SOA_COMMON_DATETIME_HXX
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <string>
#include <ctime>
#include <vector>

#include <stdlib.h>

#include <teamcenter/soa/common/SoaCommonExports.h>



namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {

struct DtElements
{
    int     year;          // YYYY
    int     month;         // 1-12
    int     day;           // 1-31
    int     hour;          // 0-23
    int     minute;        // 0-59
    int     second;        // 0-59

};


class TCSOACOMMON_API DateTime
{
public:

    /**
     * Returns an instance of the Null DateTime object.
     * This is the client equivalent of the
     * Teamcenter POM  date_t constant returned by the function POM_null_date().
     */
    static const DateTime getNullDate();


    /**
     * Default constructor creating an instance with the current date and time
     */
    DateTime();

    /**
     * Construct a DateTime for the give time_t value (seconds elapsed since Jan 1, 1970)
     *
     * @param time seconds elapsed since Jan 1, 1970
     */
    explicit DateTime( time_t time );

    /**
     * Construct a date by parsing a string with the following format:
     * yyyy-MM-ddThh:mm:ss zz:zz
     * 2005-05-20T14:32:05-08:00    The -08:00 is minus 8 hours from GTM (Pacific Standard Time)
     *
     * @param time String to parse
     */
    explicit DateTime( const std::string& time );


    /**
     * Construct a date from the given input values:
     *
     * @param year       yyyy
     * @param month      1-12 (January = 1)
     * @param day        1-31
     * @param hour       0-23
     * @param minutes    0-59
     * @param seconds    0-59
     */
    DateTime ( int year, int month, int day, int hour = 0, int minutes = 0, int seconds = 0 );

    ~DateTime(){};


    /**
     * Returns the date in a string with the format yyyy-MM-ddThh:mm:ss zz:zz
     *
     * @return The date as a string
     */
    std::string toString( ) const;

    /**
     * Returns the date in a string with the given format.
     *
     * @param format Format string with codes defined by the strftime function
     *        ( i.e. %Y = year in decimal, with the century)
     *
     * @return The date as a string
     */
    std::string toString( const std::string& format ) const;

     /**
     * Returns the date as seconds elapsed since Jan 1, 1970
     *
     * @return seconds elapsed since Jan 1, 1970
     */
    time_t toTime() const;

    /**
     * Returns the timezone offset of this date
     *
     * @return offset from GMT (minutes)
     */
    int  timeZoneOffset() const;

    int  year  () const          {return m_dateTime.year;}           //[yyyy]
    int  month () const          {return m_dateTime.month;}          //[1..12]
    int  day   () const          {return m_dateTime.day;}            //[1..31]
    int  hour  () const          {return m_dateTime.hour;}           //[0..23]
    int  minute() const          {return m_dateTime.minute;}         //[0..59]
    int  second() const          {return m_dateTime.second;}         //[0..59]

    bool operator ==(const DateTime& that) const;
    bool operator !=(const DateTime& that) const {return !operator==(that);}

    bool operator  >(const DateTime& that) const;
    bool operator  <(const DateTime& that) const;
    bool operator >=(const DateTime& that) const {return !operator<(that);}
    bool operator <=(const DateTime& that) const {return !operator>(that);}

    DateTime operator  +( const DateTime& that ) const;
    DateTime operator  -( const DateTime& that ) const;
    DateTime operator +=( const DateTime& that );
    DateTime operator -=( const DateTime& that );

    /**
     * Returns the local time-zone offset from GMT (minutes).
     *
     */
    static int getTimeZoneOffset();

    SOA_CLASS_NEW_OPERATORS

private:
    void initStatics()const;
    void init( int year, int month, int day, int hour = 0, int minutes = 0, int seconds = 0 );
    int  getLocalGMTOffset( int hour, int minute) const;
    bool isDayLight() const;

    tm dtElementsToTm( ) const;
    void tmToDtElements( const tm& date);

    DtElements           m_dateTime;


    static DtElements   s_startDay;
    static DtElements   s_endDay;
    static int          s_standardOffset;
    static int          s_daylightOffset;
    static std::string  s_NullDateString;

};

typedef std::vector<DateTime> DateTimeVector;


}}}


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
