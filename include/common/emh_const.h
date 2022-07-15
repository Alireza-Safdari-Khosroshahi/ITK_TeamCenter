/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2018.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    This include file is to define constants for eim error handling.
    The definition for EMH constants and error base values have been
    moved from tc/emh_const.h to this file as of Tc9.0..
    Starting from Tc9.0 new constants will be defined here.
*/

/*  */

#ifndef COMMON_EMH_CONST_H
#define COMMON_EMH_CONST_H

#include <common/tc_deprecation_macros.h>
#include <common/tc_ver_info.h> /* TC_MAJOR_VERSION */

/**
    @defgroup EMH_CONST Constants
    @ingroup EMH
    @{
*/

/** @if DOX_IGNORE
    The following constants indicate the base of assigned error codes for
    the appropriate module.
    Usage: #define MODULE_ERROR   (EMH_MODULE_error_base + n)
        where MODULE_ERROR is a symbolic name such as EMH_NOEBLOCK
        (1 <= n <= 999)
    Please Note:  Changes here require changes to emh.c
                  Also, you must add a call to ERROR_register_decoder_fn
                  in ERROR_store_init_table in the file error_store.cxx
@endif */
/** Error list is NULL */
#define ERROR_ERRORSTORE_NOERRORS        (EMH_EMH_error_base + 4)

/** CFI */
#define EMH_CFI_error_base                     0000

/** System Services */
#define EMH_SS_error_base                      1000

/** Preferences */
#define EMH_PREF_error_base                    1700

/** Error Message Handler */
#define EMH_EMH_error_base                     2000

/** Query subsystem messages */
#define EMH_QRY_error_base                     3000

/** Storage Manager */
#define EMH_SM_error_base                      4000

/** Process Manager */
#define EMH_PM_error_base                      5000

/** FolderLand */
#define EMH_FL_error_base                      6000

/** CXPOM */
#define EMH_CXPOM_error_base                   7000

/** Product Structure Mgr */
#define EMH_PSM_error_base                     8000

/** Application Encapsulation */
#define EMH_AE_error_base                      9000

/** System Administration */
#define EMH_SA_error_base                      10000

/** Sawindow_errors.h */
#define EMH_SA_W_ERROR_BASE                    EMH_SA_error_base +500

/** Import/export */
#define EMH_TIE_error_base                     11000

/** File Server */
#define EMH_FS_error_base                      12000

/** File Management */
#define EMH_FM_error_base                      13000

/** Volume Management */
#define EMH_VM_error_base                      14000

/** UIIL */
#define EMH_UIIL_error_base                    15000

#define EMH_ICI_error_base                     16000

/** MAIL */
#define EMH_MAIL_error_base                    17000

/** WorkSpaceObject UIF */
#define EMH_WSOUIF_error_base                  17100

/** Text server */
#define EMH_TEXT_error_base                    18000

/** GIZMO class */
#define EMH_GIZMO_error_base                   19000

/** CMMV module */
#define EMH_CMMV_error_base                    20000

/** Network services */
#define EMH_NW_error_base                      21000

/** Release management */
#define EMH_EPM2_error_base                    22000

/** Log Manager */
#define EMH_LM_error_base                      23000

/** Item Version */
#define EMH_IV_error_base                      24000

/** Item Version Folder */
#define EMH_IVF_error_base                     25000

/** General Teamcenter Engineering errors */
#define EMH_TC_error_base                      26000

/** General WSO errors */
#define EMH_WSO_error_base                     27000

/** General FORM errors */
#define EMH_FORM_error_base                    28000

/** General Teamcenter Engineering Initialization errors */
#define EMH_TCINIT_error_base                  29000

/** UG Session Mgr */
#define EMH_NXSM_error_base                    30000

/** USER Exits */
#define EMH_UE_error_base                      31000

/** Reservation errors */
#define EMH_RES_error_base                     32000

/** Process Modeling */
#define EMH_EPM_error_base                     33000

/** Business-Rules manager */
#define EMH_EBR_error_base                     34000

/** GRM errors */
#define EMH_GRM_error_base                     35000

/** Method errors */
#define EMH_METHOD_error_base                  36000

/** WorkSpace errors */
#define EMH_WS_error_base                      37000

/** Property errors */
#define EMH_PROP_error_base                    38000

/** Type errors */
#define EMH_TYPE_error_base                    39000

/** Sites (IMCs) */
#define EMH_SITE_error_base                    40000

/** ITK-visible BIER */
#define EMH_OBJIO_error_base                   41000

/** Backup/import/export/recover */
#define EMH_BIER_error_base                    41100

/** Archive/restore */
#define EMH_ARCHIVE_error_base                 41600

/** Export record */
#define EMH_IXR_error_base                     41700

/** Publication Audit Record */
#define EMH_PAR_error_base                     41800

/** Shape Data messages */
#define EMH_SDL_error_base                     42000

/** Product Structure */
#define EMH_PS_error_base                      43000

/** Electronic Work Instructions errors */
#define EMH_EWI_error_base                     44000

/** Unit Of Measure errors */
#define EMH_UOM_error_base                     45000

/** BOM module errors */
#define EMH_BOM_error_base                     46000

/** ATTR module errors */
#define EMH_ATTR_error_base                    47000

/** ITEM module errors */
#define EMH_ITEM_error_base                    48000

/** PSE user interface messages */
#define EMH_PSE_error_base                     49000

/** General user interface messages */
#define EMH_UIF_error_base                     50000

/** AOM module errors */
#define EMH_AOM_error_base                     51000

/** Change Management errors */
#define EMH_CM_error_base                      52000

/** Forms User Interface (customer ITK) errors */
#define EMH_FUI_error_base                     53000

/** LOV(List of Values) module errors */
#define EMH_LOV_error_base                     54000

/** LOV User Interface errors */
#define EMH_LOVUIF_error_base                  55000

/** DMI user errors */
#define EMH_DMI_error_base                     56000

/** STEP Errors */
#define EMH_STEP_error_base                    57000

/** Variant rule Errors */
#define EMH_VRULE_error_base                   58000

/** Mentor Integration Errors */
#define EMH_MGC_error_base                     59000

/** CAD Attribute Mapping errors */
#define EMH_ATTRMAP_error_base                 60000

/** ICM Errors */
#define EMH_ICM_error_base                     61000

/** CFM UIF Errors */
#define EMH_CFM_UIF_error_base                 62000

/** @if DOX_IGNORE
    WEB UIF errors
                                        63000

@endif */

/** Teamcenter Logistics Errors */
#define EMH_LOGISTICS_error_base               64000


/** BOB Errors */
#define EMH_BOB_error_base                     65000

/** CONFIG Errors */
#define EMH_CONFIG_error_base                  66000

/** Foundation Classes Errors */
#define EMH_FCLASSES_error_base                67000

/** Product Manufacturing Information Errors */
#define EMH_MCI0MFGCHARACTERISTICS_error_base  68000

/** Product Manufacturing Information BVR Errors */
#define EMH_MCI0MFGCHARACTERISTICSBVR_error_base 69000

/** ICT Errors */
#define EMH_ICT_error_base                     70000

/** ICS Errors */
#define EMH_ICS_error_base                     71000

/** ECM Errors */
#define EMH_ECM_error_base                     72000

/** ImanIDCreator Errors */
#define EMH_ID_error_base                      73000

/** NR (Naming Rules) Errors */
#define EMH_NR_error_base                      74000

/** BMF ERRORs */
#define EMH_BMF_error_base                     74100

/** RBF ERRORs */
#define EMH_RBF_error_base                     74300

/** CONSTANTS ERRORs */
#define EMH_CONSTANTS_error_base               74500

/** CE ERRORs */
#define EMH_CE_error_base                      74700

/** CLIPS ERRORs */
#define EMH_CLIPS_error_base                   74900

/** CMP (Generic Compare Engine) Errors */
#define EMH_CMP_error_base                     75000

/** Audit Manager errors */
#define EMH_AUDITMGR_error_base                76000

/** Teamcenter Configurator (Cfg0Configurator) module Errors */
#define EMH_CFG0CONFIGURATOR_error_base        77000

/** Subscription Manager Errors */
#define EMH_SCM_error_base                     78000

/**  Cfg0SoaConfigurator Errors*/
#define EMH_CFG0SOACONFIGURATOR_error_base     79000

/** ImanAction errors */
#define EMH_ACTION_error_base                  80000

/** ImanAction errors */
#define EMH_EVENT_error_base                   81000

/** Appearance errors */
#define EMH_APPR_error_base                    82000

/** TypeCannedMethod errors */
#define EMH_METHOD_CM_error_base               83000

/** ImanParameters errors */
#define EMH_PARAMETERS_error_base              84000

/** ImanTrushape errors */
#define EMH_TCTRUSHAPE_error_base              85000

/** Id Generation Rule errors */
#define EMH_IDGENERATION_ERROR_BASE            86000

/** Appearance Group errors */
#define EMH_APPGRP_error_base                  87000

/** Application Integration Environment errors */
#define EMH_AIE_error_base                     88000

/** Generic Relation Manager */
#define EMH_TCGRM_error_base                   89000

/** EINT Errors */
#define EMH_EINT_error_base                    90000

/** Interop related Error Messages */
#define EMH_INTEROP_error_base                 91000

/** ConfigFilterCriteria SOA module errors */
#define EMH_FND0SOACONFIGFILTERCRITERIA_error_base 92000

/** Configurator Admin - OBSOLETED */
#define EMH_FND0CONFIGURATORADMIN_error_base   93000

/** Configurator Admin SOA module errors - OBSOLETED */
#define EMH_FND0SOACONFIGURATORADMIN_error_base 94000

/**  MULTISITE TIE Errors*/
#define EMH_MULTISITE_TIE_error_base           95000

/**  TIE MULTISITE Errors*/
#define EMH_TIE_MULTISITE_error_base           96000

/**  TIE island based local/remmote checkin/out Errors */
#define EMH_TIE_ISLAND_CICO_error_base         96500

/** Ptn0PartitionTemplate  */
#define EMH_PTN0PARTITIONTEMPLATE_error_base   97000

/** TE error base ITK module */
#define EMH_TE_error_base                      98000

/** OVE error base - used to translate OVE exceptions to Teamcenter Engineering errors */
#define EMH_BOM_OVE_error_base                 99000

/** OVE error base - used to translate OVE exceptions */
#define EMH_OVE_error_base                     99900

/** Publication Record errors */
#define EMH_PUBR_error_base                    100000

/** Object Directory Services errors */
#define EMH_ODS_error_base                     100100

/** Teamcenter Engineering Distributed Services Manager errors */
#define EMH_IDSM_error_base                    100200

/** Item ID Registry errors */
#define EMH_IIR_error_base                     100300

/** Distributed Application errors */
#define EMH_DIST_error_base                    100400

/** APPREF errors */
#define EMH_APPREF_error_base                  100500

/** Project Level Security */
#define EMH_PROJECT_error_base                 101000

/** GDE */
#define EMH_GDE_error_base                     102000

/** TCConnection */
#define EMH_TCCONNECTION_error_base            103000

/** Mechatronics */
#define EMH_MECHATRONICS_error_base            104000

/** GMS */
#define EMH_GMS_error_base                     105000

/**  TraceLink Errors*/
#define EMH_TRACELINK_error_base               106000

/** Service Scheduling module Errors */
#define EMH_SSS0SVCSCHEDULING_error_base       107000

/** Material Management Module Errors */
#define EMH_MATERIALMGMT_error_base            108000

/**  FND0AUDIT_MGR Errors*/
#define EMH_FND0AUDIT_MGR_error_base           109000

/** SOA Multi-Disciplinary Object MANAGEMENT Errors */
#define EMH_SOAMDOMANAGEMENT_error_base        110000

/** Multi-Disciplinary Object module Errors */
#define EMH_MDO_error_base                     111000

/** Business Modeler IDE Audit Errors */
#define EMH_AUDITBMIDE_error_base              113000

/** Active Workspace SOA related errors */
#define EMH_SOA_AWS2_error_base                114000

/** Electronic Work Instructions SOA related errors */
#define EMH_SOA_EWI_error_base                 115000

/** Relationship Viewer SOA related errors */
#define EMH_SOA_RV1RELATIONSHIPVIEWER_error_base 116000

/** Shape Search SOA related errors */
#define EMH_SOA_SS1SHAPESEARCH_error_base      117000

/** Services Work Instructions SOA related errors */
#define EMH_SOA_SWI_error_base                 118000

/** Substance Compliance Module Errors */
#define EMH_SUBSCMPL_error_base                119000

/** International Material Data System Integration Module Errors */
#define EMH_IMDSINTEGRATION_error_base         120000

/** Lifecycle Interoperability Services Framework Errors */
#define EMH_LIS0LISFMWRK_error_base            121000

/** Lifecycle Interoperability Services Framework BMIDE Errors */
#define EMH_LIS0LISFMWRK_BMIDE_error_base      121500

/** Lifecycle Interoperability Services for Open Services for Lifecycle Collaboration (OSLC) support Errors */
#define EMH_OSL0LISOSLC_error_base             122000

/**  Linked Data Framework For Change Management Integration Errors */
#define EMH_LCM0LISCM_error_base               122500

/** Fnd0qualification module Errors */
#define EMH_FND0QUALIFICATION_error_base       123000

/** Active Workspace Systems Engineering module errors */
#define EMH_ASE0ACTIVEWORKSPACESYSENG_error_base 124000

/** Active Workspace Systems Modeling errors */
#define EMH_ASE1AWSYSTEMSMODELING_error_base   124500

/** Errors from module Pdg0designgdlines (Partitioned Design Guidelines) */
#define EMH_PDG0PTNDESIGNGDLINES_error_base    125000

/** Active workspace Occurrence Management related Errors */
#define EMH_AWB0OCCMGMT_error_base             126000

/** Active workspace Occurrence Management BOM related Errors */
#define EMH_AWB0OCCMGMTBOM_error_base          126200

/** Active workspace Occurrence Management 4th Generation Design related Errors */
#define EMH_AWB1OCCMGMT4GD_error_base          127000

/** Active Workspace Systems Engineering and 4th Generation Design alignment related Errors */
#define EMH_AWSYSENG4GDALIGNMENT_error_base    127500

/** TextServer errors */
#define EMH_TEXTSRV_error_base                 128000

/** Massive Model Visualization(MMV) Errors */
#define EMH_FND0MMV_error_base                 129000

/** Massive Model Visualization(MMV) SOA Errors */
#define EMH_FND0SOAMMV_error_base              129500

/**  Finish Management Errors*/
#define EMH_FNSHMGMT_error_base                130000

/**  Work Package Management Errors  */
#define EMH_PKGMGMT_error_base                 131000

/** Cls0Classification module errors */
#define EMH_CLS0CLASSIFICATION_error_base      132000

/** PMI(Part Manufacturing Information) */
#define EMH_PMI0PMI_error_base                 133000

/** Visualization SOA Errors */
#define EMH_SOAVISUALIZATION_error_base        134000

/**  Stock Material Errors  */
#define EMH_STOCKMATERIAL_error_base           135000

/** Teamcenter FourDPlanning Related Errors */
#define EMH_FDP0FOURDPLANNING_error_base       136000

/** TCExpress Errors */
#define EMH_EXPRESS_error_base                 137000

/** ClientServices Errors */
#define EMH_CLIENTSERVICES_error_base          138000

/** BomLite Errors */
#define EMH_BOMLITE_error_base                 139000

/** Shape Search Errors */
#define EMH_SS1_SHAPESEARCH_error_base         140000

/** AWS2 module errors */
#define EMH_AWS2_error_base                    141000

/** Relationship Viewer module errors */
#define EMH_RV1RELATIONSHIPVIEWER_error_base   142000

/** Lbr0librarymgmt module errors */
#define EMH_LBR0LIBRARYMGMT_error_base         143000

/** Scheduling Analytics errors in Schedule Manager Module */
#define EMH_SMANALYTICS_error_base             145000

/** Active Workspace Social Collaboration module errors */
#define EMH_SOCIALCOLLABORATION_error_base     146000

/** Scheduling Engine errors in Schedule Manager Module */
#define EMH_SMENGINE_error_base                147000

/** sem1serviceeventmgmtaw module errors
    Service Event, Active Workspace BOM Interface */
#define EMH_SEM1SERVICEEVENTMGMTAW_error_base  148000

/** smr1mrocoreaw module errors
    MRO Core, Active Workspace BOM Interface */
#define EMH_SMR1MROCOREAW_error_base           149000

/** spr1serviceprocessingaw module errors
    Service Processing, Active Workspace BOM Interface */
#define EMH_SPR1SERVICEPROCESSINGAW_error_base 150000

/** stp1transactionprocessingaw module errors
    Transaction Processing, Active Workspace BOM Interface */
#define EMH_STP1TRANSACTIONPROCESSINGAW_error_base 151000

/** sab1asbuiltaw module errors
    MRO As-Built, Active Workspace BOM Interface */
#define EMH_SAB1ASBUILTAW_error_base           152000

/** sam1asmaintainedaw module errors
    MRO As-Maintained, Active Workspace BOM Interface */
#define EMH_SAM1ASMAINTAINEDAW_error_base      153000

/** Teamcenter Email Polling Errors */
#define EMH_EMLPOLLING_error_base              154000

/** Automated Service Scheduling module Errors */
#define EMH_SAS0SVCAUTOSCHEDULING_error_base   155000

/** Service Forecasting module Errors */
#define EMH_SERVICEFORECASTING_error_base      156000

/** Edit Context errors */
#define EMH_FND0EDITCONTEXT_error_base         157000

/** Teamcenter Integration Framework error base */
#define EMH_TCIF_error_base                    158000

/** Active Workspace Requirements Management errors */
#define EMH_ARM0ACTIVEWORKSPACEREQMGMT_error_base 159000

/** Service Planning module Errors */
#define EMH_CMTPROCESS_error_base              160000

/** MBC0MFGBVRCORE module Errors */
#define EMH_MBC0MFGBVRCORE_error_base          161000

/** CMTAPS module Errors */
#define EMH_CMTAPS_error_base                  162000

/** Test Manager Related Errors */
#define EMH_TM0TSM_error_base                  163000

/**  Supplier Collaboration Errors*/
#define EMH_SUPPCOLL_error_base                164000

/** Product Line Plan Errors */
#define EMH_PRODLINEPLAN_error_base            165000

/**  Color Appearance Errors */
#define EMH_CLR0COLORAPPEARANCE_error_base     166000

/**  Color Rule Errors */
#define EMH_CLR1COLORRULE_error_base           167000

/**  Color BOM Errors*/
#define EMH_CBM0COLORBOMPMM_error_base         168000

/** Active Workspace Visualization errors */
#define EMH_AWV0ACTIVEWORKSPACEVIS_error_base  169000

/** Active Workspace Visualization SOA related errors */
#define EMH_SOA_AWV0ACTIVEWORKSPACEVIS_error_base 170000

/** DPM0MFK Errors */
#define EMH_DPM0MFK_error_base                 171000

/** UI Configuration module Errors */
#define EMH_UICONFIG_error_base                172000

/** UI Configuration SOA Related Errors */
#define EMH_SOAUICONFIG_error_base             173000

/** Active Workspace 4G foundation related errors */
#define EMH_FGF0AW4GFOUNDATION_error_base      174000

/** Active Workspace 4G Design related errors */
#define EMH_FGD0AW4GDESIGN_error_base          174500

/** Active Workspace 4G BOM related errors */
#define EMH_FGB0AW4GBOM_error_base             175000

/** Set-Based Traversal module Errors */
#define EMH_TRV_error_base                     176000

/** Program Planning module Errors */
#define EMH_PRG0PROGRAMINFRA_error_base        177000

/** Product Configurator Support for Structure Manager Related Errors */
#define EMH_SMC0CONFIGURATOR_error_base        178000

/** Active Workspace Program Planning related Errors */
#define EMH_PGP0AWPRGPLANNING_error_base       179000

/** CMC0CFGCM Error Base */
#define EMH_CMC0CFGCM_error_base               180000

/** BOM Management Errors */
#define EMH_BOM0BOMMANAGEMENT_error_base       181000

/** BOM Design alignment Errors */
#define EMH_BDA0BOMDESIGNALIGNMENT_error_base  182000

/** Active Workspace Massive Model Visualization errors */
#define EMH_AWV0ACTIVEWORKSPACEMMV_error_base  183000

/** Active Workspace Validation Contract Errors */
#define EMH_VCAW_error_base                    184000

/** Attribute and Product Target Management Errors */
#define EMH_ATT0ATTRTARGETMGMT_error_base      185000

/** Attribute and Product Target Management SOA Errors */
#define EMH_ATT0SOAATTRTARGETMGMT_error_base   185200

/** System Modeling Errors */
#define EMH_SYSTEMMODELING_error_base          186000

/** Diagramming Errors */
#define EMH_DIAGRAMMING_error_base             187000

/** Validation Contract Errors */
#define EMH_VC_error_base                      188000

/** Aspect Related Errors */
#define EMH_ASP0ASPECT_error_base              189000

/** Program Planning Advanced Module errors */
#define EMH_PRG1PROGRAMPLANNINGAPP_error_base  190000

/** Advanced Product Configurator */
#define EMH_CFG1CONFIGURATOR_error_base        191000

/** Advanced Product Configurator Services */
#define EMH_CFG1SOACONFIGURATOR_error_base     192000

/** Active Workspace Program Planning Advanced related Errors */
#define EMH_PGP1AWPRGPLANNINGAPP_error_base    193000

/** Teamcenter Integration 4th Generation Design Errors */
#define EMH_NXC0TCINCPD_error_base             194000
/** Active Workspace Office Export library errors */
#define EMH_AWB0ACTIVEWORKSPACEOFFICEEXPORT_error_base  196000

/** APS Configured Search (srh0apsconfiguredsearch) module errors */
#define EMH_SRH0APSCONFIGUREDSEARCH_error_base 197000

/** Active Workspace BOM errors */
#define EMH_SOA_ACTIVEWORKSPACEBOM_error_base  199000

/** ME Errors */
#define EMH_ME_error_base                      200000

/** IC Errors */
#define EMH_IC_error_base                      201000

/** RDV Errors */
#define EMH_RDV_error_base                     202000

/** Identifier Errors */
#define EMH_IDENTIFIER_error_base              203000

/** IdContext Errors */
#define EMH_IDCONTEXT_error_base               203100

/** IdDispRule Errors */
#define EMH_IDDISPRULE_error_base              203200

/** PLMXML Import/Export Errors */
#define EMH_PIE_error_base                     203300

/** AI Errors */
#define EMH_AI_error_base                      203800

/** Collaboration Context ERRORS */
#define EMH_COLLABCTX_error_base               204000

/** TcAE ERRORs */
#define EMH_TCAE_error_base                    205000

/** VALIDATION Objects ERRORs */
#define EMH_VALIDATION_error_base              206000

/** Computer Aided Engineering (CAE) ERRORS */
#define EMH_CAE_error_base                     206500

/** Exported Proxy Link Errors */
#define EMH_EPL_error_base                     207000

/** Proxy Link Errors */
#define EMH_PL_error_base                      207100

/** Proxy ERRORs */
#define EMH_PROXY_error_base                   207200

/** VIS Objects ERRORs */
#define EMH_VIS_error_base                     208000

/** VISPublish Objects ERRORs */
#define EMH_PUBLISH_error_base                 208100

/** ActionItem Objects Errors */
#define EMH_FND0ABSACTIONITEM_error_base       209000

/* STRNG module Errors */
#define EMH_STRNG_error_base                   210000

/* TC Services  Errors */
#define EMH_TCSERVICES_error_base              210500

/** ICSUTILITY Errors */
#define EMH_ICSUTIL_error_base                 211000

/** SAP integration Errors */
#define EMH_SAP_error_base                     212000

/** Translation Services Errors */
#define EMH_DISPATCHER_error_base              213000

/** Service Oriented Architecture (SOA) Services Errors */
#define EMH_SOA_error_base                     214000
#define EMH_SOACORE_error_base                 214100
#define EMH_SOASTRUCTUREMANAGEMENT_error_base  214500
#define EMH_SOADEBUGMONITOR_error_base         214600
#define EMH_SOACAD_error_base                  215000
#define EMH_SOABUSINESSMODELER_error_base      216000
#define EMH_SOAQUERY_error_base                217000
#define EMH_INTEGRATION_error_base             218000
#define EMH_SOAWORKFLOW_error_base             219000

/** ProgressData Errors */
#define EMH_PD_error_base                      220000

/** Usage Web Client (USAGEWC) Errors */
#define EMH_USAGEWC_error_base                 221000

/** Usage module(USAGE) Errors */
#define EMH_USAGE_error_base                   222000

/** Tc Requirement */
#define EMH_REQ_error_base                     223000

#define EMH_SOAREQUIREMENTSMANAGEMENT_error_base 224000

/** ManagedRelation Errors */
#define EMH_MANAGEDRELATION_error_base         225000

/** Business Modeler IDE Base Errors */
#define EMH_BMIDEBASE_error_base               226000

/** Business Modeler IDE Errors */
#define EMH_BMIDE_error_base                   226300

#define EMH_SOAMULTISITE_error_base            227000

/** Multisite private services errors */
#define EMH_MULTISITE_error_base               227500

/** Briefcase module Errors */
#define EMH_BRIEFCASE_error_base               228000

/** Vendor Management Module Errors */
#define EMH_VMS_error_base                     229000

/** SCHMGT (Scheduling in PLM1) Errors */
#define EMH_SCHMGT_error_base                  230000

/** DPV (gdis) Errors */
#define EMH_DPV_error_base                     231000

/** QSEARCH Errors */
#define EMH_QSEARCH_error_base                 232000

/**  Change Management Errors*/
#define EMH_CHGMGT_error_base                  233000

/** CHANGE MGT SOA ERRORS*/
#define EMH_SOACHANGEMGT_error_base            234000

/** Metamodel Errors */
#define EMH_META_error_base                    235000

/** MetaModel FrameWork Errors */
#define EMH_METAFRAMEWORK_error_base           236000

/** MRO Core Errors Base */
#define EMH_MROCORE_error_base                 237000

/** AsBuilt Error Base */
#define EMH_ASBUILT_error_base                 238000

/** Content Management Error Base */
#define EMH_CONTMGMT_error_base                239000
#define EMH_CONTMGMTBASE_error_base            239100
#define EMH_CONTMGMTDITA_error_base            239200
#define EMH_CONTMGMTS1000D_error_base          239300

/** MetaModel Extension FrameWork Errors */
#define EMH_EXTENSIONFRAMEWORK_error_base      240000

/** Specification Manager module Errors */
#define EMH_SPECMGR_error_base                 241000

/** AsMaintained Error Base */
#define EMH_ASMAINTAINED_error_base            242000

/** AsBuilt AsMaintained Alignment Error Base */
#define EMH_ASBASMALIGNMENT_error_base         243000

/** ServiceProcessing Error Base */
#define EMH_SERVICEPROCESSING_error_base       244000

/** ServiceEventManagement Error Base */
#define EMH_SERVICEEVENTMANAGEMENT_error_base  245000

/** TransactionProcessing Error Base */
#define EMH_TRANSACTIONPROCESSING_error_base   246000

/** ServiceRequest Error Base */
#define EMH_SERVICEREQUEST_error_base          246500

/** PKGART module Errors */
#define EMH_PKGART_error_base                  247000

/** CCDM Errors */
#define EMH_CCDM_error_base                    248000
#define EMH_PARMMGMT_error_base                248450
#define EMH_PRODUCTVARIANT_error_base          248500
#define EMH_TABLE_error_base                   248800

/** EDA Errors */
#define EMH_EDA_error_base                     249000

/** EDA library Errors */
#define EMH_EPL0EDALIBRARY_error_base          249500

/** SOA BOM Errors */
#define EMH_SOABOM_error_base                  250000

/** MFGBVR Errors */
#define EMH_MFGBVR_error_base                  251000

/** TCCORE Errors */
#define EMH_TCCORE_error_base                  252000

/** MFG Errors */
#define EMH_MFG_error_base                     253000

/** CMTMES Errors */
#define EMH_CMTMES_error_base                  254000

/** MESBVR Errors */
#define EMH_MESBVR_error_base                  254500

/** SOA WIREHARNESS Errors */
#define EMH_SOAWIREHARNESS_error_base          255000

/** Variant Solve Errors */
#define EMH_CFG_error_base                     256000
#define EMH_VARSOLVE_error_base                257000

/** SoaConfiguration Module Errors*/
#define EMH_SOACONFIGURATION_error_base        258000

/*Teamcenter Document Management SOA Errors */
#define EMH_SOADOCUMENTMANAGEMENT_error_base   259000

/** Document Management Errors */
#define EMH_DOCMGT_error_base                  260000

/**  Issue Management Errors **/
#define EMH_ISSUEMGMT_error_base               261000

/** Document Management App Errors */
#define EMH_DOCMGTAPP_error_base               262000

/** VIEWER module Errors */
#define EMH_VIEWER_error_base                  263000

/**  BOOLEANMATH Errors*/
#define EMH_BOOLEANMATH_error_base             264000

/** functionality errors */
#define EMH_FUNCTIONALITY_error_base           265000

/**  SECore Errors */
#define EMH_SECORE_error_base                  266000

/** Network Editor Errors */
#define EMH_FND0NWEDITOR_error_base            267000

/** CondValidation */
#define EMH_CONDVALIDATION_error_base          268000

/** L10N module Errors */
#define EMH_L10N_error_base                    269000

/** Teamcenter ContractManagement related Errors */
#define EMH_CONTRACTMANAGEMENT_error_base      270000

/** L10N module Errors */
#define EMH_SOAAI_error_base                   271000

/** Teamcenter WebDAV service Errors */
#define EMH_TCWEBDAV_error_base                272000

/** SHAREDCACHE ERRORS */
#define EMH_SHAREDCACHE_error_base             273000

/** SHAREDCACHETYPES ERRORS */
#define EMH_SHAREDCACHETYPES_error_base        274000

/** Teamcenter CFilter module Errors */
#define EMH_CFILTER_error_base                 275000

/** Cpd0cd */
#define EMH_CPD0CD_error_base                  276000

/** Cpd0WorkSet */
#define EMH_CPD0WORKSET_error_base             277000

/** Application model module Errors */
#define EMH_MDL0MODEL_error_base               278000

/** Rlz0Realization */
#define EMH_RLZ0REALIZATION_error_base         279000

/** Ptn0Partition */
#define EMH_PTN0PARTITION_error_base           280000

/** Systems Engineering module Errors */
#define EMH_SYSTEMSENGINEERING_error_base      281000

/** BehaviorModeling Errors */
#define EMH_BHM0_error_base                    282000

/** Cpd0WorkSet SOA */
#define EMH_SOA_CPD0WORKSET_error_base         283000

/** Cpd0Cd SOA */
#define EMH_SOA_CPD0CD_error_base              283500

/** MODELCORE SOA */
#define EMH_SOA_MODELCORE_error_base           284000

/** Memory Management Error Base */
#define EMH_MEM0MEMMGT_error_base              285000

/** Fnd0formulamgmt */
#define EMH_FND0FORMULAMGMT_error_base         285500

/** CMTMESINTEG Errors */
#define EMH_CMTMESINTEG_error_base             286000

/** MESBVRINTEG Errors */
#define EMH_MESBVRINTEG_error_base             286500

/** ISO26262 - Functional Safety Template for ISO 26262 Compliance */
#define EMH_ISF0_error_base                    287000

/** E&S - Electronics and Semi-Conductor Templates */
#define EMH_IES0_error_base                    288000

/** Authorization module Errors */
#define EMH_AUTHORIZATION_error_base           290000

/** Service Planning module Errors */
#define EMH_SERVICEPLANNING_error_base         291000

/** Index BOM errors */
#define EMH_IBOM_error_base                    292000

/** Softlines, Hardlines And Footwear SOA Module Errors **/
#define EMH_SOARETAIL_error_base               293000

/** Softlines, Hardlines And Footwear Module Errors **/
#define EMH_RETAIL_error_base                  294000

/** Change Management CPD Interface errors */
#define EMH_CPC0CPDCM_error_base               295000

/** Build condition computation errors */
#define EMH_BCS0BUILDCONDITIONS_error_base     296000

/** System Synthesis Modeling Errors */
#define EMH_SSM0SYSTEMSYNTHESISMODELING_error_base     297000

/**Active Workspace Material Management Error Base */
#define EMH_MATERIALMGMTAW_error_base          299000

/** Teamcenter Manufacturing SOA Related Errors */
#define EMH_SOAMANUFACTURING_error_base        300000

#define EMH_SOAPROJECTMANAGEMENT_error_base    301000

/** Multi-disciplined Connectivity Errors */
#define EMH_MDCONNECTIVITY_error_base          302000

/** Multi-disciplined Connectivity and 4GD Alignment Errors */
#define EMH_MDCCPDALIGNMENT_error_base         302500

/** Multi-disciplined Connectivity SOA Related Errors */
#define EMH_SOAMDCONNECTIVITY_error_base       303000

/**Active Workspace Vendor Management Error Base */
#define EMH_VM1VENDORMANAGEMENTAW_error_base   311000

/**Active Workspace Substance Compliance Error Base */
#define EMH_SUBSCMPLAW_error_base              312000

/** Target Management Module errors */
#define EMH_TGM0TARGETMANAGEMENT_error_base    313000

/** Teamcenter Design Disclosure Related errors **/
#define EMH_FND0DISCLOSURE_error_base          315000

/** Change Management 4th Generation Interface errors */
#define EMH_FGC0CM4G_error_base                317000

/** Transformer errors */
#define EMH_XFORMER_error_base                 318000

/** Retail Footwear and Apparel Module Errors **/
#define EMH_RET1RETAILAW_error_base            319000

/** Image Compression Errors */
#define EMH_IMAGECOMPRESSION_error_base        320000

/** Foundation Base Utilities errors */
#define EMH_BASE_UTILS_error_base              322000

/** Change Management Color BOM Interface Related Errors */
#define EMH_CBC0CMCLR_error_base               323000

/** Active Workspace Substance Compliance IMDS (International Material Data System) integration  error base */
#define EMH_IMDSINTEGRATIONAW_error_base       324000

/** Closed Loop Integration Framework Errors */
#define EMH_CLI_error_base                     325000

/** National Language Support (NLS) error base */
#define EMH_NLS_error_base                     326000

/** Manufacturing Resource Manager Related Errors */
#define EMH_MRM_error_base                     327000

/**  NX/TC 4GD Validation Errors */
#define EMH_NX_4GD_VALIDATION_error_base       328000

/** Schedule Manager for Active Workspace Related Errors */
#define EMH_SAW1PROJECTMANAGEMENTAW_error_base 329000

/** Program Schedule Manager for Active Workspace Related Errors */
#define EMH_PPSMINTERFACE_error_base           330000

/** LDF Services - Requirements Management Related Errors */
#define EMH_LRM0LISRM_error_base               331000

/** Product Configurator for Active Workspace Related Errors */
#define EMH_PCA0AWCONFIGURATOR_error_base      333000

/** Product Configurator for Active Workspace SOA Related Errors */
#define EMH_PCA0AWCONFIGURATOR_soa_error_base  340000

/** Branching and Versioning Errors */
#define EMH_BHV0BRANCHFOUNDATION_error_base    341000

/** Branching and Versioning SOA Errors */
#define EMH_BHV0SOABRANCHFOUNDATION_error_base 342000

/** Office Online SOA Related Errors */
#define EMH_OO1SOAOFFICEONLINE_error_base      347000

/** Advanced PLM Services (APS) Core Errors  */
#define EMH_APS0APSCORE_error_base             348000

/** Effectivity Solve Errors */
#define EMH_EFFSOLVE_error_base                350000

/** Manufacturing Change Management errors */
#define EMH_MPC0MPRCM_error_base               351000

/** Automation Electric Design Errors */
#define EMH_AED0AUTOMATIONELECTRICDESIGN_error_base 352000

/** Consumer Product Management errors */
#define EMH_PMG0CPMGMT_error_base              353000

/** Active Workspace CAE module errors */
#define EMH_CAEAWS_error_base                  355000

/** Active Workspace Stock Material errors */
#define EMH_SM1AWSTOCKMATERIAL_error_base      356000
/**  Planning MBOM related Errors */
#define EMH_PMB0MBOM_error_base                357000


/** Branch Data Organization Errors */
#define EMH_BDO0BRANCHDATAORGANIZATION_error_base 357000

/** Branch Data Organization SOA Errors */
#define EMH_BDO0SOABRANCHDATAORGANIZATION_error_base 357500

/** Branch Data Organization Errors */
#define EMH_BDO0BRANCHDATAORGANIZATION_error_base 357000

/** Branch Data Organization SOA Errors */
#define EMH_BDO0SOABRANCHDATAORGANIZATION_error_base 357500

/** LDF Services - Embedded Software Management Related Errors */
#define EMH_LES0LISESM_error_base              358000

/** Active Workspace 4G Plant BOM related errors */
#define EMH_FGP0AW4GPBOM_error_base            359000

/** Embedded Software Management Related Errors */
#define EMH_ESW0ESMGMT_error_base              360000

/** Active Workspace Finish Management error base */
#define EMH_FSH1AWFINISHMANAGEMENT_error_base  362000

/** Alignment of 4G PM with design PS related errors */
#define EMH_BOM0PSDALIGNMENT_error_base        363000

/** Fastener Management Errors */
#define EMH_FND0FASTENERMGMT_error_base        364000

/** Composites errors */
#define EMH_COMPOSITES_error_base              365000

/** Massive Model Visualization Support for CPD and Related errors.*/
#define EMH_CPD0MMV_error_base                 366000

/** Active Workspace Contract Data Management errors */
#define EMH_CDM1AWCONTRACTMANAGEMENT_error_base 369000

/** Active Workspace Supplier Collaboration errors */
#define EMH_SUPPCOLLAW_error_base               370000

/** Order Management errors */
#define EMH_ORD0ORDERMANAGEMENT_error_base      371000

/** Simulation Process Management Related Errors. */
#define EMH_CAE0SIMULATIONPROCESSMANAGEMENT_error_base 372000

/** Lifecycle Interoperability Services Workflow Errors */
#define EMH_LIS0LDFEPM_error_base              373000

/** Active Workspace Advanced PLM Services core related errors */
#define EMH_APS1APSCORE_error_base             374000

/** Active Workspace Requirements and Systems Engineering related Errors. */
#define EMH_ARM1AWREQMGMTSE_error_base         375000

/** Asynchronous Teamcenter Integration Support Related Errors*/
#define EMH_NXA0TCIN_error_base                376000

/** Classification Standard Taxonomy Support related errors */
#define EMH_CST_error_base                     377000

/** FoundationBase errors */
#define EMH_BASE_error_base                    379000

/** Active Workspace Work Package errors */
#define EMH_WPM1AWPKGMGMT_error_base           380000

/** Easy Plan Line Balancing module Errors */
#define EMH_ELB0LINEBALANCING_error_base       386000

/** Active Workspace Document Management Errors */
#define EMH_AWDOCMGT_error_base                387000

/** Teamcenter Intosite integration related errors */
#define EMH_INS0INS_error_base                 388000

/** Configurable Validation Errors */
#define EMH_CONFIGURABLE_VALIDATION_error_base 389000

/** Easy Plan MFGBVR Maturity module Errors */
#define EMH_EPC0MFGBVRMATURITY_error_base      390000

/** Easy Plan Product Configurator module Errors */
#define EMH_EPP0PRODUCTCONFIGURATOR_error_base 391000

/** Participant related errors */
#define EMH_PARTICIPANT_error_base             392000

/**  Intosite Errors */
#define EMH_TCIINTOSITE_error_base             393000

/** Native Quality Center Applications related Errors */
#define EMH_QC0QUALITYCENTERBASE_error_base    394000

/** Quality Center Manager for Active Workspace Errors */
#define EMH_AQC0QCMAW_error_base               395000

/** Capital Asset Lifecycle Management module Errors */
#define EMH_PDM0PLANTDATAMGMT_error_base       396000

/** Failure Mode Effect Analysis(FMEA) Errors */
#define EMH_QFM0QCFMEA_error_base              397000

/** Social Integration Service module Errors */
#define EMH_SIS0SOCIALINT_error_base           399000

/** TcSoaAdministration module errors */
#define EMH_SOAADMINISTRATION_error_base       400000

/** Manufacturing Process Planning for Electronics module Errors */
#define EMH_MPE0ELECPROCPLAN_error_base        401000

/** Feature Planning in Active Workspace Errors*/
#define EMH_PCA1AWCONFIGURATOR_error_base      402000

/** Engineering Views Errors */
#define EMH_EVM0VIEWMGMT_error_base            403000

/** Engineering Views Active Workspace Errors */
#define EMH_EVM1VIEWMGMTAW_error_base          404000

/** MFGSPC errors */
#define EMH_MFGSPC_error_base                  405000

/** Teamcenter Microservice module errors */
#define EMH_MICROSERVICES_error_base           406000

#if TC_MAJOR_VERSION <= 14000
#define EMH_TCMICROSERVICESUTILS_error_base           EMH_MICROSERVICES_error_base

/** @deprecated #EMH_TCMICROSERVICESUTILS_error_base deprecated in Teamcenter 13.1. Use #EMH_MICROSERVICES_error_base instead. */
TC_DEPRECATED_PREPROCESSOR("13.1", EMH_TCMICROSERVICESUTILS_error_base, "EMH_MICROSERVICES_error_base");

#endif /* #if TC_MAJOR_VERSION <= 14000 */

/** Active Workspace Capital Asset Lifecycle Management module Errors */
#define EMH_PDM1PLANTDATAMGMTAW_error_base     407000

/** Verification Management errors */
#define EMH_IAV0VERIFICATIONMGMT_error_base    408000

/** Active WorkSpace Verification Management errors */
#define EMH_IAV1VERIFICATIONMGMTAW_error_base    409000

/** Work Breakdown Structure errors */
#define EMH_WBS0WORKBREAKDOWNSTRUCTURE_error_base    410000

/** Product Master related errors */
#define EMH_EBM0ENTERPRISEBOM_error_base       412000

/** Active workspace Enterprise BOM related errors */
#define EMH_EBM1AWEBOM_error_base              413000

/** EasyPlan WorkInstructions errors */
#define EMH_EPW0WORKINSTRUCTIONS_error_base    414000

/** Active Workspace Bom Errors */
#define EMH_AWB0ENTCBA_error_base              415000

/** Enterprise CAD-BOM Alignment Capability Errors  */
#define EMH_FND0ENTCBA_error_base              416000

/** Active workspace Service forecasting module errors */
#define EMH_SSF1SERVICEFORECASTINGAW_error_base 417000

/** Constraint Solver related errors */
#define EMH_constraintsolver_error_base        419000

/** Control Inspection Plan for ActiveWorkspace Related Errors */
#define EMH_ACP0AWCONTROLPLAN_error_base       420000

/** Control Inspection Plan Related Errors */
#define EMH_CIP0CONTROLINSPPLAN_error_base     421000

/** Quality Issue Management and Problem Solving data model Related Errors */
#define EMH_CAW0CAPAONAWC_error_base           422000

/** Quality Action Management Related Errors */
#define EMH_QAM0QUALITYACTIONMGMT_error_base   423000

/** Classification common API related errors */
#define EMH_CLA_error_base                     424000

/** Active Workspace Active Modeler related errors */
#define EMH_AM1ACTIVEMODELER_error_base        425000

/** Multi-BOM Manager related errors */
#define EMH_MBM0MULTIBOMMGMT_error_base        426000

/** Product Master Automation Errors */
#define EMH_PMA0AUTOMATION_error_base          427000

/** Active Workspace Vendor Management module errors */
#define EMH_VENDORMANAGEMENT_error_base        429000

/** Feature Planning module errors */
#define EMH_CFP0_FEATUREPLANNING_error_base    430000

/** Weight and Balance management related errors */
#define EMH_WNB0WEIGHTANDBALANCE_error_base    431000

/** Weight and Balance management for Active Workspace related errors */
#define EMH_WNB1WEIGHTANDBALANCEAW_error_base  432000

/** OData Service for Teamcenter related errors */
#define EMH_ODS0OBJECTDATASERVICES_error_base  433000

/** Organization Breakdown Structure module errors */
#define EMH_OBS0ORGBREAKDOWN_error_base        439000

/** Integrated Program Planning Execution module errors */
#define EMH_IPP0IPPECORE_error_base            440000

/** Integrated Program Planning Contract Management module errors */
#define EMH_ICD0IPPCDMEXT_error_base           442000

/** Active Workspace NX Integration Framework related errors */
#define EMH_AWN0NX_error_base                  443000

/** Active Workspace Resource Occurrences Management Errors */
#define EMH_AWMRM0OCCMGMT_error_base           446000

/** Product Configurator Feature Planning module errors */
#define EMH_PFP0_FEATUREPLANNING_error_base    447000

/** Data Share Dashboard (dsdashboard) module errors */
#define EMH_DSDASHBOARD_error_base             448000

/** Active Workspace service planning and service processing alignment related errors */
#define EMH_SSPSPRALIGNMENTAW_error_base       450000

/** Import BOM module errors for Active Workspace */
#define EMH_AWP0OCCMGMT_error_base             452000

/** TRAINING AND QUALIFICATION Related Errors */
#define EMH_TQ0_TRAINING_QUALIFICATION_error_base    453000

/** Compliance Checker module errors */
#define EMH_COMPLIANCECHECKER_error_base       454000

/** Active Workspace Active Collaboration module errors */
#define EMH_AC0ACTIVECOLLABORATION_error_base  455000

/** Active Workspace XLS BOM SOA errors */
#define EMH_AWB0SOAXLSBOM_error_base           456000

/** Active Workspace XLS BOM errors */
#define EMH_AWB0XLSBOM_error_base              458000

/** Active Workspace Quality Audit related errors */
#define EMH_QA0QUALITYAUDIT_error_base         460000

/** Medical Device UDI Solution related errors */
#define EMH_MEDICALDEVICEUDI_error_base        461000

/** POM - copied over from NX */
#define EMH_POM_error_base                     515000

/** AM - copied over from NX */
#define EMH_AM_error_base                      525000

/** XTM - copied over from NX */
#define EMH_XTM_error_base                     540000

/** EIM - copied over from NX */
#define EMH_EIM_error_base                     545000

/** CFM - copied over from NX */
#define EMH_CFM_error_base                     710000

/** ImanactionHandler and related errors */
#define EMH_HANDLER_error_base                 720000

/** ImanEventType and related errors */
#define EMH_EVENTTYPE_error_base               730000

/**  EventTypeMapping errors */
#define EMH_EVENTTYPEMAPPING_error_base        732000

/** ImanEventManager errors */
#define EMH_EVENTMGR_error_base                732500

/** NX Manager I-deas Errors */
#define EMH_IDS_error_base                     800000

/**  ADSFOUNDATION Errors*/
#define EMH_ADSFOUNDATION_error_base           900000

/** USER exit functions */
#define EMH_USER_error_base                    919000

/** NX/TC API error codes - copied over from NX */
#define EMH_API_error_base                     920000

/**  REXP Errors - copied over from NX */
#define EMH_REXP_error_base                    935000

/** @if DOX_IGNORE
    Please Note:  Changes here require adding a call to
    ERROR_register_decoder_fn in ERROR_store_init_table in
    the file error_store.cxx
@endif */

/** @} */

#endif /* COMMON_EMH_CONST_H */
