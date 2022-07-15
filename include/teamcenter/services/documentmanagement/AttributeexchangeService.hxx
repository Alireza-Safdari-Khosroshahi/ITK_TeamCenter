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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_ATTRIBUTEEXCHANGESERVICE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_ATTRIBUTEEXCHANGESERVICE_HXX

#include <teamcenter/services/documentmanagement/_2011_06/Attributeexchange.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/documentmanagement/DocumentManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Documentmanagement
        {
            class AttributeexchangeService;

/**
 * This service provides operations for metadata exchange between Teamcenter properties
 * and the application client (for example: Microsoft Office Word application).   It
 * supports the metadata exchange for the following property types: <b>char, double,
 * float, short, int, logical, string, </b>and<b> date</b>.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoadocumentmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoadocumentmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API AttributeexchangeService
    : public Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange
{
public:
    static AttributeexchangeService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation processes the metadata exchange mapping information between the client
     * application and Teamcenter from the provided input list of <b>ResolveAttrMappingsAndGetPropertiesInfo</b>
     * structure (containing the metadata exchange mapping information from the client application).
     * The operation then gets and returns the property  values of the corresponding Teamcenter
     * object from provided input information.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Metadata exchange between Teamcenter and Microsoft Office Word application</b>
     * <br>
     * From the Teamcenter client for Microsoft Office Word 2010, a user opens and checks
     * out a WordX Dataset.  User then clicks on the Teamcenter ribbon and clicks on Attribute
     * Exchange> Configurations> Create.  From here user can set up the metadata exchange
     * between the properties of the Microsoft Office Word file properties and the properties
     * of the Teamcenter object.
     * <br>
     * <br>
     * In the configuration, user can set the direction of the metadata exchange either
     * as File to Teamcenter, Teamcenter to File, or Two Way.  In this case, user selects
     * Teamcenter to File for the metadata exchange from the client to Teamcenter.  User
     * sets up the property mapping by selecting a file property (Comments for example)
     * and selecting a Teamcenter object property (object_desc for example), and saves the
     * attribute exchange configuration.  User then clicks on Attribute Exchange>Reload
     * button.  The Microsoft Office Word initiates this operation and gets Teamcenter object
     * property (object_desc for example) value back.  To verify the client file property
     * gets updated, from Microsoft Office Word menu File, select Info (in the left panel),
     * then select Properties (in the right panel), then select Show Document Panel.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param info
     *        It contains the attribute exchange mappings information.
     *
     * @return
     *         <i>ResolveAttrMappingsAndGetProperpertiesResponse</i> structure which includes the
     *         <i>ServiceData</i> with some of possible Partial Errors listed below for any object
     *         that fails in the metadata exchange and a list of <i>ResultAndGetResult</i> structure
     *         (containing the <i>WorkspaceObject</i> that initiates the operation with the  corresponding
     *         list of resolved metadata exchange mapping information: the client property name,
     *         the Teamcenter property value, success or failure, any errors).
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">262019&nbsp;&nbsp;&nbsp;&nbsp;The Mapping object Attriubte Name is
     *         empty.
     *         </li>
     *         <li type="disc">262021&nbsp;&nbsp;&nbsp;&nbsp;The Relation object is not valid.
     *         </li>
     *         <li type="disc">262022&nbsp;&nbsp;&nbsp;&nbsp;The Mapping path is not valid.
     *         </li>
     *         <li type="disc">262024&nbsp;&nbsp;&nbsp;&nbsp;No object matches the provided Relation
     *         name.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndGetPropertiesResponse resolveAttrMappingsAndGetProperties ( const std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndGetPropertiesInfo >& info ) = 0;

    /**
     * This operation processes the metadata exchange mapping information between the client
     * and Teamcenter from the provided input list of <b>ResolveAttrMappingsAndSetPropertiesInfo</b>
     * structure (containing the metadata exchange mapping information from the client application).
     * The operation sets the Teamcenter property values based on the provided input information.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Metadata exchange between Teamcenter and Microsoft Office Word application</b>
     * <br>
     * <br>
     * From the Teamcenter client for Microsoft Office Word 2010, a user opens and checks
     * out a WordX Dataset.  User then clicks on the Teamcenter ribbon and clicks on Attribute
     * Exchange >Configurations>Create.  From here user can set up the metadata exchange
     * between the properties of the Microsoft Office Word file and the properties of the
     * Teamcenter object.
     * <br>
     * <br>
     * In the configuration, user can set the direction of the metadata exchange either
     * as File to Teamcenter, Teamcenter to File, or Two Way.  In this case, user selects
     * File to Teamcenter for the metadata exchange, pick a file property (Comment for example),
     * pick a Teamcenter object property (object_desc for example), and save the attribute
     * exchange configuration.  From Microsoft Office Word menu File, select Info (left
     * panel), then select Properties (right panel)>Show Document Panel.  Update the Comments
     * text box in the Document Properties Panel with some text.  Now select Teamcenter
     * ribbon and click on Save.  Save and check in the Dataset.  During this process, the
     * Microsoft Office Word initiates this operation and updates Teamcenter object property
     * (object_desc for example) value.  User can verify the Teamcenter object property
     * (object_desc for example) by login to a Teamcenter client such as Rich Application
     * Client (RAC), do a View properties on the Teamcenter object.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param info
     *        It contains information for Resolving the attribute exchange and the value to be
     *        set on the Teamcenter attribute.
     *
     * @return
     *         <i>ResolveAttrMappingsAndSetProperpertiesResponse</i> structure which includes the
     *         <i>ServiceData</i> with some possible Partial Errors listed below for any object
     *         that fails in the metadata exchange and a list of <i>ResolveAndSetResult</i> structure
     *         (containing the <i>WorkspaceObject</i> that has failure along with the corresponding
     *         list of client properties and error messages).
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndSetPropertiesResponse resolveAttrMappingsAndSetProperties ( const std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndSetPropertiesInfo >& info ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AttributeexchangeService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

