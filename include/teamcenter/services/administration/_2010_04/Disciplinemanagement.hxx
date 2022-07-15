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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2010_04_DISCIPLINEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2010_04_DISCIPLINEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Discipline.hxx>


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
            namespace _2010_04
            {
                class Disciplinemanagement;

class TCSOAADMINISTRATIONSTRONGMNGD_API Disciplinemanagement
{
public:

    struct GetDisciplineResponse;

    /**
     * This structure is the object returned by this operation. It holds the Discipline
     * object found and ServiceData object.
     */
    struct GetDisciplineResponse
    {
        /**
         * The discipline object found with the given name.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Discipline>  discipline;
        /**
         * The object which holds the possible error in the search of the discipline.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Disciplinemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

