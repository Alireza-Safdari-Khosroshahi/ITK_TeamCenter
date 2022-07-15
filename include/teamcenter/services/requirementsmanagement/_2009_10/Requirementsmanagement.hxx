/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2009_10_REQUIREMENTSMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2009_10_REQUIREMENTSMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Fnd0ListsParamReqments.hxx>
#include <teamcenter/soa/client/model/Fnd0ParamReqmentRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Requirementsmanagement
        {
            namespace _2009_10
            {
                class Requirementsmanagement;

class TCSOAREQUIREMENTSMANAGEMENTSTRONGMNGD_API Requirementsmanagement
{
public:

    struct GetStdNoteParamAndValues;
    struct StdNoteInput;
    struct OpenStdNoteContents;
    struct OpenStdNoteResponse;
    struct SetStdNoteDetails;
    struct SetStdNoteParameters;
    struct SetStdNoteResponse;
    struct SetStdNoteResult;

    /**
     * <code>GetStdNoteParamAndValues</code> structure defines the name and value pair of
     * each parameter for <b>Fnd0ParamReqmentRevision</b>. Each Parameter has list of values.
     * And <code>assignedValue</code> has the value of parameter for <b>Fnd0ParamReqmentRevision</b>
     * when it is in context.
     */
    struct GetStdNoteParamAndValues
    {
        /**
         * Parameter name. Example-Temperature
         */
        std::string parameter;
        /**
         * List of values for given parameter. Example. For above parameter Temperature list
         * of values can be : 0, 10, 20, 30, 40
         */
        std::vector< std::string > values;
        /**
         * Current value of Parameter. Example. From the list of values as mentioned for values
         * elements, the assignedValue for any specific context with relation <code>Fnd0ListsParamReqments</code>
         * can be say "10" or "20" for selected parameter type.
         */
        std::string assignedValue;
    };

    /**
     * <code>StdNoteInput</code> structure represents the input parameters of setting Standard
     * note values. It includes <b>Standard Note</b>/<b>Parametric Requirement Revision</b>
     * object and the object of <code>Fnd0ListsParamReqments</code> relation by which it
     * is attached to any <b>Item</b>/ <b>ItemRevision</b>.
     */
    struct StdNoteInput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Tag of <b>Fnd0ParamReqmentRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ParamReqmentRevision>  standardNote;
        /**
         * Relation object of type <b>Fnd0ListParamRequirements</b> by which <b>Fnd0ParamReqmentRevision</b>
         * is attached to selected object revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ListsParamReqments>  stdNoteRelation;
    };

    /**
     * OpenStdNoteContents structure contains input structure provided to this operation
     * StdNoteInput, note text of <b>Fnd0ParamReqmentRevision</b> object which user want
     * to see/edit, body_text of <b>Fnd0ParamReqmentRevision</b> object, and map of the
     * parameter and values for the <b>Fnd0ParamReqmentRevision</b> object.
     */
    struct OpenStdNoteContents
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * <code>StdNoteInput</code> structure given as input this operation.
         */
        Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::StdNoteInput inputDetails;
        /**
         * A list of <code>GetStdNoteParamAndValues</code> which gives the list of parameters
         * and their values for <b>Fnd0ParamReqmentRevision</b> object.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::GetStdNoteParamAndValues > parametersOnRelation;
        /**
         * Note Text of <b>Fnd0ParamReqmentRevision</b> object. In this note text user can type
         * any text, and parameter, and its value pair in below format
         * <br>
         * [<param1 name>: value1, value2,..]
         * <br>
         * Example [Temperature:0,10,20,30]
         */
        std::string noteText;
        /**
         * body_text property of <b>Fnd0ParamReqmentRevision</b> object.
         */
        std::string templateText;
    };

    /**
     * <code>OpenStdNoteResponse</code> structure represents list of <code>OpenStdNoteContents</code>
     * structure along with the ServiceData.
     */
    struct OpenStdNoteResponse
    {
        /**
         * A list of <code>GetStdNoteParamAndValues</code> structure that hold the information
         * of <b>Fnd0ParamReqmentRevision</b> objects parameter values set in the context, note
         * text, body_text property of <b>Fnd0ParamReqmentRevision</b>, and input structure
         * as <code>StdNoteInput</code>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::OpenStdNoteContents > openNoteObjectsDetails;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData sreviceData;
    };

    /**
     * <code>SetStdNoteDetails</code> structure represents <b>Standard Note</b>/<b>Parametric
     * Requirement</b> details with note relation object, and values to set on Standard
     * note relation.
     */
    struct SetStdNoteDetails
    {
        /**
         * A <code>StdNoteInput</code> structure that hold the information of <b>Standard note</b>
         * object and <b>Standard note</b> relation.
         */
        Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::StdNoteInput inputNoteDetails;
        /**
         * List of Values to be set on <b>Standard note</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::SetStdNoteParameters > values;
    };

    /**
     * <code>SetStdNoteParameters</code> structure represents Parameter and its value to
     * be set on <b>Standard Note</b> <b>Relation</b> object.
     */
    struct SetStdNoteParameters
    {
        /**
         * Name of parameter.
         */
        std::string parameter;
        /**
         * Value to be set on parameter from the list of values.
         */
        std::string value;
    };

    /**
     * <code>SetStdNoteResponse</code> structure represents list of <code>SetStdNoteResult</code>
     * structure containing <b>Standard Note</b> details along with the ServiceData.
     */
    struct SetStdNoteResponse
    {
        /**
         * A list of <code>SetStdNoteResult</code> structure that hold the information of <b>Standard
         * Note</b> objects.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::SetStdNoteResult > resultObjects;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>SetStdNoteResult</code> structure defines the output for each note when set
     * Note SOA operation is invoked. It returns the new note text value set on parametreized<b>
     * Requirement</b>.
     */
    struct SetStdNoteResult
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * <b>Standard Note</b>/<b>Parametric Requirement Revision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0ParamReqmentRevision>  standardNote;
        /**
         * Value of new Note Text on <b>Standard Note</b>/<b>Parametric Requirement Revision</b>
         * object
         */
        std::string noteText;
    };




    /**
     * This operation helps to open <b>Fnd0ParamReqment</b> object, or its Revision <b>Fnd0ParamReqmentRevision</b>
     * contents in Teamcenter MS Word view. User will get the note text associated with
     * the selected <b>Fnd0ParamReqmentRevision</b> allowing editing in that view. Opening
     * <b>Fnd0ParamReqment</b>/ <b>Fnd0ParamReqmentRevision</b> happens in two different
     * ways:
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;In context with <code>Fnd0ListsParamReqments</code> relation:
     * In this case, operation gives the Parameter/ value pairs selected in context for
     * the parent object of <code>Fnd0ListsParamReqments</code>, allowing editing the values.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Without context: In this case, it gives note text associated
     * for the <b>Fnd0ParamReqmentRevision</b> for view/edit purpose.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Suppose user created <b>Fnd0ParamReqment</b> object, and
     * now wants to see/edit note text of it, then opening Teamcenter MS Word view, user
     * will see it, and can edit it.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Suppose user has attached any <b>Fnd0ParamReqment</b>/<b>Fnd0ParamReqmentRevision</b>
     * object to any other <b>Item</b>/<b>ItemRevision</b> object with <code>Fnd0ListsParamReqments</code>
     * relation, and now wants to edit/view parameter values which are set while attaching
     * this <b>Fnd0ParamReqment</b>/<b>Fnd0ParamReqmentRevision</b>, then opening Teamcenter
     * MS Word view will show it.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A list of structures containing <b>Fnd0ParamReqmentRevision</b> object with <code>Fnd0ListsParamReqments</code>
     *        relation object by which <b>Fnd0ParamReqmentRevision</b> is attached to any other
     *        object.
     *
     * @return
     *         Result of operation is including resultant <code>OpenStdNoteContents</code> structures
     *         along with ServiceData. This structure will contain input object, Note Text, Template
     *         text, and Parameter and Values details in selected context.
     *         <br>
     *         Any failure to getting <code>Fnd0ParamReqment</code> values will be returned with
     *         client id mapped to error message in the ServiceData list of partial errors.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::OpenStdNoteResponse openStdNote ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::StdNoteInput >& input ) = 0;

    /**
     * Sets the parameters and their values on <b>Standard Note</b>/<b>Parametric Requirement</b>.
     * This SOA operation can set values on one or more <b>Standard Note</b>/<b>Parametric
     * Requirement</b> in one operation call. When any <b>Standard Note</b>/<b>Parametric
     * Requirement</b> attached to any <b>ItemRevision</b> it will get attached with relation
     * <b>Fnd0ListsParamRequirements</b> (Parametric Requirements Lists). In that context
     * if that <b>Standard Note</b>/<b>Parametric Requirement</b> object is selected, and
     * edited in <b>MS Word</b> view, then saving of editing values from this view will
     * be set on this <b>Standard Note</b>/<b>Parametric Requirement</b> using this SOA.
     * This SOA will set those parameters and their values on given relation object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can edit, and set <b>Standard Note</b>/<b>Parametric Requirement</b> Parameter
     * values using <b>MS Word view</b> in Teamcenter. This view can be launched using Window->Show
     * view->Other->Teamcenter->MS Word
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        List of standard note input details with their values on parameters to be set.
     *
     * @return
     *         Result of SOA operation is including resultant <code>SetStdNoteResult</code> structure
     *         along with ServiceData. This structure will contain <b>Standard Note</b>/<b>Parametric
     *         Requirement</b> object and it's Note Text.
     *         <br>
     *         Any failure to setting <b>Standard Note</b> values will be returned with client id
     *         mapped to error message in the ServiceData list of partial errors.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::SetStdNoteResponse setStdNote ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::SetStdNoteDetails >& input ) = 0;


protected:
    virtual ~Requirementsmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_undef.h>
#endif

