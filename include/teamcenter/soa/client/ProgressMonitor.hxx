/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_PROGRESSMONITOR_HXX
#define TEAMCENTER_SOA_CLIENT_PROGRESSMONITOR_HXX

#include <stdio.h>
#include <string>
#include <map>


#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

/**
 * The <code>ProgressMonitor</code> class is used to track the progress of
 * a given task. The methods in this class are invoked by code that 
 * performs the activity.
 * <p>
 * All activity is broken down into a linear sequence of tasks against
 * which progress is reported. A task is started with the method <code>start(string, int)</code> 
 * followed by any number <code>worked()</code>.  When the task is eventually completed, a 
 * <code>done()</code> notification is called.
 * <p>
 * A request to cancel an operation can be signaled using the 
 * <code>cancel</code> method.  Operations taking a progress
 * monitor are expected to poll the monitor (using <code>isCanceled</code>)
 * periodically and abort at their earliest convenience.  Operation can however 
 * choose to ignore cancellation requests.
 */
class TCSOACLIENTMNGD_API ProgressMonitor
{
public:
    SOA_CLASS_NEW_OPERATORS

     ProgressMonitor();
    virtual ~ProgressMonitor();

     /**
      * Notifies that the work is starting and the total amount of work
      * that will be required to complete this task.
      *
      * @param name          The name of the task.
      * @param totalWork     The total number of work units into which
      *                      the main task is been subdivided.
      */
    virtual void start( const std::string& name, int totalWork )=0;



    /**
     * Notifies that a given number of work unit of the main task
     * has been completed. Note that this amount represents an
     * installment, as opposed to a cumulative amount of work done
     * to date.
     *
     * @param work the number of work units just completed
     */
    virtual void worked(int work) = 0;

    /**
     * Notifies that the work is done; that is, either the main task is completed 
     * or the user canceled it. 
     */
     virtual void done() = 0;


    /**
     * Returns whether cancellation of current operation has been requested.
     * Long-running operations should poll to see if cancellation
     * has been requested.
     *
     * @return <code>true</code> if cancellation has been requested,
     *          and <code>false</code> otherwise
     */
    bool isCanceled() const;


    /**
     * Sets the cancel state.
     */
    void cancel();

protected:




private:
    bool m_canceled;
};


}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>


#endif

