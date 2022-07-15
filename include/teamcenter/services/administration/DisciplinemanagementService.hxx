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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION_DISCIPLINEMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION_DISCIPLINEMANAGEMENTSERVICE_HXX

#include <teamcenter/services/administration/_2010_04/Disciplinemanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            class DisciplinemanagementService;

/**
 * This service provides operations to manage Discipline objects in Organization application.
 * Use cases include addition of new Discipline objects, modification of existing Discipline
 * objects, and removal of existing Discipline objects. It also allows users to retrieve
 * Discipline object information and find Discipline objects. It currently supports
 * following operations:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Retrieve existing Discipline objects.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaadministrationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaadministrationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAADMINISTRATIONSTRONGMNGD_API DisciplinemanagementService
    : public Teamcenter::Services::Administration::_2010_04::Disciplinemanagement
{
public:
    static DisciplinemanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation gets the <b>Discipline</b> object with given name. If no discipline
     * object is found with the given name, the returned discipline object would be null.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Organization Management - It maps Organization Management services documentation
     * to BMIDE
     *
     * @param disciplineName
     *        This parameter specifies the name of the discipline object to be found.
     *
     * @return
     *         This operation returns GetDisciplineResponse object. The GetDisciplineResponse contains
     *         the found discipline object and ServiceData. If discipline with given name is not
     *         found, it will return error message "Discipline  not found" with error code <b>10146</b>
     *         in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Administration::_2010_04::Disciplinemanagement::GetDisciplineResponse getDiscipline ( const std::string&  disciplineName ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DisciplinemanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/administration/Administration_undef.h>
#endif

