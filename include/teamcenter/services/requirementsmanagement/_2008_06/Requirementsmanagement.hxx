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

#ifndef TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2008_06_REQUIREMENTSMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2008_06_REQUIREMENTSMANAGEMENT_HXX

#include <teamcenter/services/requirementsmanagement/_2007_01/Requirementsmanagement.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>


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
            namespace _2008_06
            {
                class Requirementsmanagement;

class TCSOAREQUIREMENTSMANAGEMENTSTRONGMNGD_API Requirementsmanagement
{
public:

    struct GetContentInput1;

    /**
     * <code>GetContentInput1</code> structure represents the parameters required to open
     * requirement in <b>MSWord</b>.
     */
    struct GetContentInput1
    {
        /**
         * <b>Fulltext</b> object that user want to view.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  objectToProcess;
        /**
         * For viewing and editing content without template this parameter should be <b>MSWordXML</b>.
         * <br>
         * For viewing and editing object by applying template this parameter should be <b>MSWordXMLLive</b>.
         * <br>
         * <br>
         */
        std::string applicationFormat;
        /**
         * This parameter is not used currently.
         */
        std::string templateId;
        /**
         * For viewing and editing content without template this parameter should be false.
         * <br>
         * For viewing and editing object by applying template this parameter should be true.
         */
        bool applyTemplates;
    };




    /**
     * The SOA operation is responsible for retrieving contents of objects of type <b>SpecElement</b>.
     * It can be used to view content of <b>SpecElement</b> in word. SOA also provides capability
     * to view contents by applying default templates.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can open requirements in word using default templates or they can open content
     * (body text) in word for view and edit purpose.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of structures containing the required information to open requirement content
     *        in word.
     *
     * @return
     *         A vector of transientFileReadTickets containing the document having rich text is
     *         returned to the user.
     *
     *
     * @exception ServiceException
     *           If there is any error during generating transient file read ticket due to a configuration
     *           issue at the server, then the operation throws a service exception. Example- If the
     *           transient volume directory is not configured at the server then the FMS fails to
     *           generate a file at the server and subsequent file download operation fails. In such
     *           situation a service exception is thrown.
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::GetRichContentResponse getRichContent ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2008_06::Requirementsmanagement::GetContentInput1 >& inputs ) = 0;


protected:
    virtual ~Requirementsmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_undef.h>
#endif

