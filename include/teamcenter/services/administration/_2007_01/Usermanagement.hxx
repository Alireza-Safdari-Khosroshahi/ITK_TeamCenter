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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2007_01_USERMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2007_01_USERMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Discipline.hxx>
#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/Role.hxx>
#include <teamcenter/soa/client/model/User.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            namespace _2007_01
            {
                class Usermanagement;

class TCSOAADMINISTRATIONSTRONGMNGD_API Usermanagement
{
public:

    struct DisciplineObject;
    struct CreateDisciplinesIn;
    struct CreateDisciplinesOutput;
    struct CreateDisciplinesResponse;
    struct DisciplineLevel;
    struct DisciplineUser;

    /**
     * This structure holds initial property values for a new discipline object and the
     * corresponding client ID.
     */
    struct DisciplineObject
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify returned CreateDisciplinesOutput
         * element and partial errors associated with the DisciplineObject input.
         */
        std::string clientId;
        /**
         * The name of the new <b>Discipline</b> object to be created.
         */
        std::string name;
        /**
         * The description text of the new <b>Discipline</b> object to be created.
         */
        std::string description;
        /**
         * The default rate property of the new <b>Discipline</b> object to be created.
         */
        double defaultRate;
        /**
         * The list of <b>Discipline</b> level.
         */
        std::vector< Teamcenter::Services::Administration::_2007_01::Usermanagement::DisciplineLevel > levels;
        /**
         * The list of DisciplineUser objects which specifies user members for the new <b>Discipline</b>
         * to be created.
         */
        std::vector< Teamcenter::Services::Administration::_2007_01::Usermanagement::DisciplineUser > users;
    };

    /**
     * This structure holds a DisciplineObject object which specifies the values of a new
     * Discipline object. as well as the parent group for the new discipline.
     */
    struct CreateDisciplinesIn
    {
        /**
         * The object with initial data for the creation of a new <b>Discipline</b> object.
         */
        Teamcenter::Services::Administration::_2007_01::Usermanagement::DisciplineObject discipline;
        /**
         * The parent group of the new Discipline object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group;
        /**
         * The role for the <b>Discipline</b> object. However it is not currently supported
         * by this operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Role>  role;
    };

    /**
     * This structure holds the newly created <b>Discipline</b> object and corresponding
     * client ID.
     */
    struct CreateDisciplinesOutput
    {
        /**
         * Identifying string from the source DisciplineObject.
         */
        std::string clientId;
        /**
         * The new <b>Discipline</b> object created in this operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Discipline>  discipline;
    };

    /**
     * This structure holds a list of newly created <b>Discipline</b> objects.
     */
    struct CreateDisciplinesResponse
    {
        /**
         * List of CreateDisciplinesOutput objects, one for each CreateDisciplinesIn object.
         */
        std::vector< Teamcenter::Services::Administration::_2007_01::Usermanagement::CreateDisciplinesOutput > output;
        /**
         * The object which holds the partial errors that occurred during creation of new <b>Discipline</b>
         * objects with all newly created discipline object in its created object list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Struct containing the discipline level name and number attribute information.
     */
    struct DisciplineLevel
    {
        /**
         * levelName
         */
        std::string levelName;
        /**
         * levelNumber
         */
        int levelNumber;
    };

    /**
     * This structure  holds a user and its discipline level name.
     */
    struct DisciplineUser
    {
        /**
         * The Teamcenter <b>User</b> object to be added to the new discipline.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * Not supported.
         */
        std::string levelName;
    };




    /**
     * This operation creates a list of new <b>Discipline</b> objects based on the list
     * of CreateDisciplineIn objects. If  parent group is specified in the CreateDisciplinesIn
     * object, the discipline objects would be added into the group. This operation requires
     * system administration or group administration privilege.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Organization Management - It maps Organization Management services documentation
     * to BMIDE
     *
     * @param disciplines
     *        A list of CreateDisciplinesIn objects to specify initial data for the new discipline
     *        objects and parent group. A new discipline object is created for each CreateDisciplinesIn
     *        object in the list.
     *
     * @return
     *         It returns a CreateDisciplinesResponse object which contains a list of CreateDisciplinesOutput
     *         objects one for each CreateDisciplinesIn object, and a ServiceData element. The newly
     *         created discipline objects are added to the created object list of the ServiceData
     *         as well. If the given discipline name in a CreateDisciplineIn object exists, it will
     *         return error message "The discipline name is used by another discipline (either its
     *         discipline name or translations)" with error code <b>10183</b>.  If the login user
     *         is not system administrator or group administrator, it will return error message
     *         "User is not a system administrator or a group administrator" with error code <b>10013</b>.
     *
     */
    virtual Teamcenter::Services::Administration::_2007_01::Usermanagement::CreateDisciplinesResponse createDisciplines ( const std::vector< Teamcenter::Services::Administration::_2007_01::Usermanagement::CreateDisciplinesIn >& disciplines ) = 0;


protected:
    virtual ~Usermanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

