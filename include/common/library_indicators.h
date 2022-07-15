/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    The definitions for unique numeric library codes have moved from
    tc/library_indicators.h to this file.Starting from Tc9.0 all
    unique numeric library codes are defined here.

    ABOUT THESE NUMBERS

    These \#defines are used to give each library module a UNIQUE
    numeric code, so that the preprocessor macro

    @code
      #if IPLIB == libqry
    @endcode

    behaves. Despite appearances, this is a NUMERIC comparison,
    because libqry is -10066, and IPLIB may be defined to be libqry,
    and hence also -10066. Or IPLIB may be defined to be libae, in
    which case it will really be -10000.

    When adding a new library to this list...

    THE NUMBER ALLOCATED TO EVERY LIBRARY MUST BE UNIQUE,
    but it doesn't matter what the number is!

    Either:
    <ol>
    <li>add to the end of the list, with the next unused number, or
    <li>re-order the list of numbers and list of libraries
    </ol>

    Changing the library/number correlation doesn't require a full re-build on
    NT (although MAKE will try to perform one) because the numbers are
    never encoded into .obj files: they're only 'live' during compilation itself.
*/

/*  */

#ifndef COMMON_LIBRARY_INDICATORS_H_INCLUDED
#define COMMON_LIBRARY_INDICATORS_H_INCLUDED

#define libae                       -10000
#define libaie                      -10001
#define libaie_acad                 -10002
#define libaie_hm                   -10003
#define libaie_se                   -10004
#define libaie_nx                   -10005
#define libappr                     -10006
#define libarchive                  -10007
#define libaudit_mgr                -10008
#define libbackup                   -10009
#define libbom                      -10010
#define libbmidebase                -10011
#define libcfm                      -10012
#define libcxpom                    -10013
#define libdmi                      -10014
#define libbmf                      -10015
#define libcollabctx                -10016
#define libcae                      -10017
#define librbf                      -10018
#define libbmide                    -10019

/*@if DOX_IGNORE
    Break the number-run so you needn't edit the whole file
@endif */

#define libecm                      -10020
#define libeint                     -10021
#define libeintstub                 -10022
#define libepm                      -10023
#define libFnd0audit_mgr            -10024
#define libEpl0edalibrary           -10025
#define libMgd0mgd                  -10026
#define libdispatcher               -10027
/*#define libets_user_exits           -10028   NO LONGER IN USE */
#define libfclasses                 -10029
#define libform                     -10030
#define libgrm                      -10031
#define libconstants                -10032
#define libce                       -10033
#define libclipsutil                -10034
#define libnxclone                  -10035

/* @if DOX_IGNORE
    Break the number-run so you needn't edit the whole file
@endif */

#define libics                      -10036
#define libict                      -10037
#define libtc                       -10038
#define libMci0mfgcharacteristics   -10039
#define libMci0mfgcharacteristicsbvr -10040
#define libtccore                   -10041
#define libtctrushape               -10042
/*#define libtcupdate                 -10043   NO LONGER IN USE */
#define libinternal_exits           -10044
#define libmgd0mdccpdalignmentdispatch -10045
#define libitk                      -10046
#define libmgd0soamdccpdalignment   -10047
#define liblov                      -10048
#define libme                       -10049
#define libmfg                      -10050
#define libmfgbvr                   -10051
#define libmgc                      -10052
#define libmechatronics             -10053
#define libfunctionality            -10054
#define libicsie                    -10055
#define libmfgcpd                   -10056
#define libmgd0soamdccpdalignmentstrong     -10057
#define libmgd0soamdccpdalignmentstrongmngd -10058
#define libpdg0ptndesigngdlines     -10059

/** @if DOX_IGNORE
    Break the number-run so you needn't edit the whole file
@endif */

#define libobjio                    -10060
#define libproperty                 -10061
#define libps                       -10062
#define libMdc0mdc                  -10063
#define libmdc0mdconnectivitydispatch -10064
#define libpublication              -10065
#define libqry                      -10066
#define librdv                      -10067
#define libres                      -10068
#define libmdc0soamdconnectivity    -10069
#define libtccoreext                -10070
#define libreq                      -10071
#define libtie                      -10072
#define libbriefcase                -10073
#define libvalidation               -10074
#define libFnd0nweditor             -10075
#define libsecore                   -10076
#define libcfilter                  -10077
#define libmdc0soamdconnectivitystrong -10078
#define libmdc0soamdconnectivitystrongmngd -10079

//* @if DOX_IGNORE
//    Break the number-run so you needn't edit the whole file
//@endif */

#define libsa                       -10080
#define libss                       -10082
#define libstep                     -10083
#define libstubs                    -10084
#define libsub_mgr                  -10085
#define libtextsrv                  -10086
#define libLbr0librarymgmt          -10087
#define libnxmgr_im                 -10088
#define libwproxy                   -10089
#define libMdo0Mdo                  -10090
#define libuser_exits               -10091
#define libvis                      -10092
#define libvispublish               -10093
#define libFnd0mmv                  -10094
#define libCfg0configurator         -10095
#define libmdo0soamdomangement           -10096
#define libmdo0soamdomangementstrongmngd -10097
#define libmdo0soamdomangementstrong     -10098
#define libFnd0tcif                 -10099

//* @if DOX_IGNORE
//    May as well keep non-/vobs/src libraries distinct, I suppose:
//@endif */

#define libtcscript                 -10100
#define libaiwebservice             -10101
#define libtc_utils                 -10102
#define libicctskel                 -10103
#define libicctimpl                 -10104
#define libtcgateway                -10105
#define libtcxsd                    -10106
#define libserver_exits             -10107
#define libinternal_server_exits    -10108
#define libusage                    -10109
#define libusagewc                  -10110
#define libuserver                  -10111

#define libschmgt                   -10112
#define libbob                      -10113
#define libconfig                   -10114
#define libgms                      -10115
#define libssrsccuaclient           -10116
#define libassy_jt                  -10117
#define libvm                       -10118
#define libtc_transform             -10119
#define libclips                    -10120
#define libmeta                     -10121
#define libmetaframework            -10122
#define libtcgsoap                  -10123
#define libmrocore                  -10124
#define libqsearch                  -10125
#define libasbuilt                  -10126
#define libcba                      -10127
#define libsystemsengineering       -10128

#define libconfigurator             -10130
#define libfnd0booleansolve         -10131
#define libbooleanmath              -10132
#define libFnd0profiler             -10133
#define libmld                      -10134
#define libcbaext                   -10135
#define libFnd0formulamgmt          -10136
#define libLgt0logisticsmfg         -10137
#define libLgt0logistic             -10138
#define libCfg9testconfigurator     -10139

#define libeffectivitymanagement    -10140

#define libmesinteg                 -10150
#define libmesbvrinteg              -10151
#define libauditbmide               -10152

#define libsmengine                 -10153
#define libsmanalytics              -10154

#define libSmd0sysmodeling          -10155
#define libSmd0sysmodelingdispatch  -10156

#define libSmc0psmcfgsupport        -10157

#define libAed0automationelectricdesign         -10158
#define libAed0automationelectricdesigndispatch -10159
#define libads0soaadsfoundation                 -10294
#define libads0soaadsfoundationstrongmngd       -10295
#define libads0soaadsfoundationstrong           -10296

#define libcae0soasimproc                       -10297
#define libcae0soasimprocstrongmngd             -10298
#define libcae0soasimprocstrong                 -10299

#define libcba1soacbaext                        -10300
#define libcba1soacbaextstrongmngd              -10301
#define libcba1soacbaextstrong                  -10302

#define libcls0soaclassificationcore            -10303
#define libcls0soaclassificationcorestrongmngd  -10304
#define libcls0soaclassificationcorestrong      -10305

#define libcpd0soacpdcore                       -10306
#define libcpd0soacpdcorestrongmngd             -10307
#define libcpd0soacpdcorestrong                 -10308

#define libesm0soaesmbase                       -10309
#define libesm0soaesmbasestrongmngd             -10310
#define libesm0soaesmbasestrong                 -10311

#define libex2soaexpressaddons                  -10312
#define libex2soaexpressaddonsstrongmngd        -10313
#define libex2soaexpressaddonsstrong            -10314

#define libfdp0soafourdplanning                 -10315
#define libfdp0soafourdplanningstrongmngd       -10316
#define libfdp0soafourdplanningstrong           -10317

#define libfnd0soaauditmanager                  -10318
#define libfnd0soaauditmanagerstrongmngd        -10319
#define libfnd0soaauditmanagerstrong            -10320

#define libfnd0soacodecoverage                  -10321
#define libfnd0soacodecoveragestrongmngd        -10322
#define libfnd0soacodecoveragestrong            -10323

#define libfnd0soaconfigfiltercriteria          -10324
#define libfnd0soaconfigfiltercriteriastrongmngd -10325
#define libfnd0soaconfigfiltercriteriastrong    -10326

#define libfnd0soaconfiguratoradmin             -10327
#define libfnd0soaconfiguratoradminstrongmngd   -10328
#define libfnd0soaconfiguratoradminstrong       -10329

#define libfnd0soadebugmonitor                  -10330
#define libfnd0soadebugmonitorstrongmngd        -10331
#define libfnd0soadebugmonitorstrong            -10332

#define libfnd0soadiagramming                   -10333
#define libfnd0soadiagrammingstrongmngd         -10334
#define libfnd0soadiagrammingstrong             -10335

#define libfnd0soammv                           -10336
#define libfnd0soammvstrongmngd                 -10337
#define libfnd0soammvstrong                     -10338

#define libfnd0soanotification                  -10339
#define libfnd0soanotificationstrongmngd        -10340
#define libfnd0soanotificationstrong            -10341

#define libfnd0soawproxy                        -10342
#define libfnd0soawproxystrongmngd              -10343
#define libfnd0soawproxystrong                  -10344

#define liblbr0soalibrarymanagement             -10345
#define liblbr0soalibrarymanagementstrongmngd   -10346
#define liblbr0soalibrarymanagementstrong       -10347

#define libmat1soamaterialmgmt                  -10348
#define libmat1soamaterialmgmtstrongmngd        -10349
#define libmat1soamaterialmgmtstrong            -10350

#define libmci0soapmimanagement                 -10351
#define libmci0soapmimanagementstrongmngd       -10352
#define libmci0soapmimanagementstrong           -10353

#define libmdl0soamodelcorestrongmngd           -10355
#define libmdl0soamodelcorestrong               -10356

#define libmdo0soamdomanagement                 -10357
#define libmdo0soamdomanagementstrongmngd       -10358
#define libmdo0soamdomanagementstrong           -10359

#define libmei0soamesinteg                      -10360
#define libmei0soamesintegstrongmngd            -10361
#define libmei0soamesintegstrong                -10362

#define libptn0soapartition                     -10363
#define libptn0soapartitionstrongmngd           -10364
#define libptn0soapartitionstrong               -10365

#define librlz0soarealization                   -10366
#define librlz0soarealizationstrongmngd         -10367
#define librlz0soarealizationstrong             -10368

#define libsci0soaimdsintegration               -10369
#define libsci0soaimdsintegrationstrongmngd     -10370
#define libsci0soaimdsintegrationstrong         -10371

#define libscp0soasubscmpl                      -10372
#define libscp0soasubscmplstrongmngd            -10373
#define libscp0soasubscmplstrong                -10374

#define libsss0soasvcscheduling                 -10375
#define libsss0soasvcschedulingstrongmngd       -10376
#define libsss0soasvcschedulingstrong           -10377

#define libtcglobalmultisite                    -10378
#define libtcglobalmultisitestrongmngd          -10379
#define libtcglobalmultisitestrong              -10380

#define libtcintegration                        -10381
#define libtcintegrationstrongmngd              -10382
#define libtcintegrationstrong                  -10383

#define libtcmultisite                          -10384
#define libtcmultisitestrongmngd                -10385
#define libtcmultisitestrong                    -10386

#define libtcsoaasbasmalignment                 -10387
#define libtcsoaasbasmalignmentstrongmngd       -10388
#define libtcsoaasbasmalignmentstrong           -10389

#define libtcsoaasmaintained                    -10390
#define libtcsoaasmaintainedstrongmngd          -10391
#define libtcsoaasmaintainedstrong              -10392

#define libtcsoabehaviormodeling                -10393
#define libtcsoabehaviormodelingstrongmngd      -10394
#define libtcsoabehaviormodelingstrong          -10395

#define libtcsoacae                             -10396
#define libtcsoacaestrongmngd                   -10397
#define libtcsoacaestrong                       -10398

#define libtcsoaissuemanagement                 -10399
#define libtcsoaissuemanagementstrongmngd       -10400
#define libtcsoaissuemanagementstrong           -10401

#define libtcsoaparametermanagement             -10402
#define libtcsoaparametermanagementstrongmngd   -10403
#define libtcsoaparametermanagementstrong       -10404

#define libtcsoasrmintegration                  -10405
#define libtcsoasrmintegrationstrongmngd        -10406
#define libtcsoasrmintegrationstrong            -10407

#define libtcsoasvcrequest                      -10408
#define libtcsoasvcrequeststrongmngd            -10409
#define libtcsoasvcrequeststrong                -10410

#define libtcsoasystemsengineering              -10411
#define libtcsoasystemsengineeringstrongmngd    -10412
#define libtcsoasystemsengineeringstrong        -10413

#define libWdM0Soaweldmanagement                -10414
#define libWdM0Soaweldmanagementstrongmngd      -10415
#define libWdM0Soaweldmanagementstrong          -10416

#define libsc0soasuppliercollaboration          -10417
#define libsc0soasuppliercollaborationstrongmngd    -10418
#define libsc0soasuppliercollaborationstrong    -10419

#define libmci0soamodelpmimanagement            -10500
#define libmdo0soamodelmdo                      -10501
#define libmei0soamodelmesinteg                 -10502
#define libsss0soamodelservicescheduling        -10503
#define libtcsoamodeladschangemanagement        -10504
#define libtcsoamodelasmaintained               -10505
#define libtcsoamodelbehaviormodeling           -10506
#define libtcsoamodelcba                        -10507
#define libtcsoamodelcbaext                     -10508
#define libtcsoamodelcdm0contractmanagement     -10509
#define libtcsoamodelclassificationcore         -10510
#define libtcsoamodelcm                         -10511
#define libtcsoamodelmes                        -10512
#define libtcsoamodelfnshmgmt                   -10513
#define libtcsoamodelcpdcore                    -10514
#define libtcsoamodelemps                       -10515
#define libtcsoamodelesddm                      -10516
#define libtcsoamodelesddmscm                   -10517
#define libtcsoamodelsci0imdsintegration        -10518
#define libtcsoamodelissuemanagement            -10519
#define libtcsoamodellibrarymanagement          -10520
#define libtcsoamodelmaterialmgmt               -10521
#define libtcsoamodelmdccpdalignment            -10522
#define libtcsoamodelmdconnectivity             -10523
#define libtcsoamodelmodelcore                  -10524
#define libtcsoamodelpartition                  -10525
#define libtcsoamodelpenetrationmgmt            -10526
#define libtcsoamodelworkpackagemanagement      -10527
#define libtcsoamodelrealization                -10528
#define libtcsoamodelserviceeventmanagement     -10529
#define libtcsoamodelserviceprocessing          -10530
#define libtcsoamodelservicerequest             -10531
#define libtcsoamodelstockmaterial              -10532
#define libtcsoamodelsubscmpl                   -10533
#define libtcsoamodeltransactionprocessing      -10534
#define libtcsoamodelweldmanagement             -10535
#define libtcsoamodelsc0suppliercollaboration   -10536
#define libconstraintsolver                     -10537
#define libosl0soamodellisoslc                  -10538
#define libpdg0soamodelptndesigngdlines         -10539
#define libtcsoamodelplp0prodlineplan           -10540
#define libtcsoamodelpmi                        -10541
#define libsmc0soamodelpsmcfgsupport            -10542
#define libssm0soamodelsystemsynthesismodeling  -10543
#define libtcsoamodelsspspralignment            -10544
#define libtcsoamodelsystemsengineering         -10545
#define libtcsoamodeltranslationservice         -10546
#define libpmg0soamodelcpmgmt                   -10547
#define libvariabilityadaptor                   -10548
#define libbdo0soamodelbranchdataorganization   -10549
#define libcrf0soamodelcprfoundation            -10550
#define librse0soamodeltcrsenablement           -10551
#define libap0soamodeladvanceplanner            -10552

#define llibmci0soamodelpmimanagementmngd       -10600
#define libmdo0soamodelmdomngd                  -10601
#define libmei0soamodelmesintegmngd             -10602
#define libsss0soamodelserviceschedulingmngd    -10603
#define libtcsoamodeladschangemanagementmngd    -10604
#define libtcsoamodelasmaintainedmngd           -10605
#define libtcsoamodelbehaviormodelingmngd       -10606
#define libtcsoamodelcbamngd                    -10607
#define libtcsoamodelcbaextmngd                 -10608
#define libtcsoamodelcdm0contractmanagementmngd -10609
#define libtcsoamodelclassificationcoremngd     -10610
#define libtcsoamodelcmmngd                     -10611
#define libtcsoamodelcpdcoremngd                -10612
#define libtcsoamodelempsmngd                   -10613
#define libtcsoamodelesddmmngd                  -10614
#define libtcsoamodelesddmscmmngd               -10615
#define libtcsoamodelfnshmgmtmngd               -10616
#define libtcsoamodelmesmngd                    -10617
#define libtcsoamodelsci0imdsintegrationmngd    -10618
#define libtcsoamodelissuemanagementmngd        -10619
#define libtcsoamodellibrarymanagementmngd      -10620
#define libtcsoamodelmaterialmgmtmngd           -10621
#define libtcsoamodelmdccpdalignmentmngd        -10622
#define libtcsoamodelmdconnectivitymngd         -10623
#define libtcsoamodelmodelcoremngd              -10624
#define libtcsoamodelpartitionmngd              -10625
#define libtcsoamodelpenetrationmgmtmngd        -10626
#define libtcsoamodelworkpackagemanagementmngd  -10627
#define libtcsoamodelrealizationmngd            -10628
#define libtcsoamodelserviceeventmanagementmngd -10629
#define libtcsoamodelserviceprocessingmngd      -10630
#define libtcsoamodelservicerequestmngd         -10631
#define libtcsoamodelstockmaterialmngd          -10632
#define libtcsoamodelsubscmplmngd               -10633
#define libtcsoamodeltransactionprocessingmngd  -10634
#define libtcsoamodelweldmanagementmngd         -10635
#define libtcsoamodelsc0suppliercollaborationmngd    -10636
#define libCpc9testcpdcm                        -10637
#define libosl0soamodellisoslcmngd              -10638
#define libpdg0soamodelptndesigngdlinesmngd     -10639
#define libtcsoamodelplp0prodlineplanmngd       -10640
#define libtcsoamodelpmimngd                    -10641
#define libsmc0soamodelpsmcfgsupportmngd        -10642
#define libssm0soamodelsystemsynthesismodelingmngd    -10643
#define libtcsoamodelsspspralignmentmngd        -10644
#define libtcsoamodelsystemsengineeringmngd     -10645
#define libtcsoamodeltranslationservicemngd     -10646
#define libpmg0soamodelcpmgmtmngd               -10647
#define libbdo0soamodelbranchdataorganizationmngd   -10649
#define libcrf0soamodelcprfoundationmngd        -10650
#define librse0soamodeltcrsenablementmngd       -10651
#define libap0soamodeladvanceplannermngd        -10652

#define libresource_browser                   -12000
#define libfoundationdispatch                 -12001
#define libscmccdispatch                      -12002
#define libtranslationservicedispatch         -12003
#define libvendormanagementdispatch           -12004
#define libadsfoundation                      -12005

#define libcm                                 -12006
#define libcmdispatch                         -12007
#define libextensionframework                 -12008
#define s_edif200                             -12009

#define libmrocoredispatch                    -12010
#define libasbuiltdispatch                    -12011

#define libdocmgt                             -12012
#define s_edif300                             -12013

#define libcbadispatch                        -12014
#define libcbaextdispatch                     -12015

#define libspecmgr                            -12100
#define libspecmgrdispatch                    -12101
#define libsadsfoundationdispatch             -12102

#define libcpgmaterials                       -12104
#define libcpgmaterialsdispatch               -12105

#define libcontmgmt                           -12106
#define libcontmgmtbase                       -12107
#define libcontmgmtdita                       -12108
#define libcontmgmts1000d                     -12109

#define libtcinit                             -12110

#define libccdm                               -12111
#define libproductvariant                     -12112
#define libadschangemanagement                -12113
#define libadschangemanagementdispatch        -12114

#define libsmartuibldr                        -12115
#define libdocmgtapp                          -12116
#define libsystemsengineeringdispatch         -12117

#define libcontmgmts1000d40                   -12118

#define libMem0memmgt                         -12119

#define libnls                                -12120

#define libtable_trx                          -12121

/* SOA Service Framwork*/
#define libtcsoacommon                        -13001
#define libtcsoalateload                      -13002
#define libtcsoaclientmngd                    -13003
#define libtcsoaclient                        -13004
#define libtctp                               -13005

/* CDM Libraries*/
#define libtcsoamodelacadgmomngd              -13010
#define libtcsoamodeladsfoundationmngd        -13011
#define libtcsoamodelasbuiltmngd              -13012
#define libtcsoamodelbrndmgmtmngd             -13013
#define libtcsoamodelchangemanagementmngd     -13014
#define libtcsoamodelcmtebopmngd              -13015
#define libtcsoamodelcmtemservermngd          -13016
#define libtcsoamodelcmtpadtwpmngd            -13017
#define libtcsoamodelcontmgmtbasemngd         -13018
#define libtcsoamodelcontmgmtditamngd         -13019
#define libtcsoamodelcontmgmts1000dmngd       -13020
#define libtcsoamodelcpgmaterialsmngd         -13021
#define libtcsoamodeldpvmngd                  -13022
#define libtcsoamodeledalibrarymngd           -13023
#define libtcsoamodeledaservermngd            -13024
#define libtcsoamodelesmbasemngd              -13025
#define libtcsoamodelesmprocessormngd         -13026
#define libtcsoamodelesmsoftwaremngd          -13027
#define libtcsoamodelfpmgmtmngd               -13028
#define libtcsoamodelgmdpvmngd                -13029
#define libtcsoamodelgmomngd                  -13030
#define libtcsoamodelhrnmngd                  -13031
#define libtcsoamodelmrocoremngd              -13032
#define libtcsoamodelpkgartmngd               -13033
#define libtcsoamodelscdtmngd                 -13034
#define libtcsoamodelscmccmngd                -13035
#define libtcsoamodelspecmgrmngd              -13036
#define libtcsoamodeltcaemngd                 -13037
#define libtcsoamodelvendormanagementmngd     -13038
#define libtcsoamodelvisualizationmngd        -13039
#define libtcsoamodelccdmmngd                 -13040
#define libtcsoamodelproductvariantmngd       -13041
#define libaed0soamodelautomationelectricdesignmngd  -13042
#define libaps0soamodelapscoremngd            -13043
#define libcfg1soamodelconfiguratormngd          -13044
#define libtcsoamodelcontmgmts1000d40mngd      -13045
#define libfdp0soamodelfourdplanningmngd      -13046
#define liblrm0soamodellisrmmngd              -13047
#define libtcsoamodelmesissuemgmtmngd          -13048
#define libtcsoamodelnx0tcinmngd              -13049

#define libtcsoamodelacadgmo                  -13060
#define libtcsoamodeladsfoundation            -13061
#define libtcsoamodelasbuilt                  -13062
#define libtcsoamodelbrndmgmt                 -13063
#define libtcsoamodelchangemanagement         -13064
#define libtcsoamodelcmtebop                  -13065
#define libtcsoamodelcmtemserver              -13066
#define libtcsoamodelcmtpadtwp                -13067
#define libtcsoamodelcontmgmtbase             -13068
#define libtcsoamodelcontmgmtdita             -13069
#define libtcsoamodelcontmgmts1000d           -13070
#define libtcsoamodelcpgmaterials             -13071
#define libtcsoamodeldpv                      -13072
#define libtcsoamodeledalibrary               -13073
#define libtcsoamodeledaserver                -13074
#define libtcsoamodelesmbase                  -13075
#define libtcsoamodelesmprocessor             -13076
#define libtcsoamodelesmsoftware              -13077
#define libtcsoamodelfpmgmt                   -13078
#define libtcsoamodelgmdpv                    -13079
#define libtcsoamodelgmo                      -13080
#define libtcsoamodelhrn                      -13081
#define libtcsoamodelmrocore                  -13082
#define libtcsoamodelpkgart                   -13083
#define libtcsoamodelscdt                     -13084
#define libtcsoamodelscmcc                    -13085
#define libtcsoamodelspecmgr                  -13086
#define libtcsoamodeltcae                     -13087
#define libtcsoamodelvendormanagement         -13088
#define libtcsoamodelvisualization            -13089
#define libtcsoamodelccdm                     -13090
#define libtcsoamodelproductvariant           -13091
#define libaed0soamodelautomationelectricdesign  -13092
#define libaps0soamodelapscore                -13093
#define libcfg1soamodelconfigurator              -13094
#define libtcsoamodelcontmgmts1000d40          -13095
#define libfdp0soamodelfourdplanning          -13096
#define liblrm0soamodellisrm                  -13097
#define libtcsoamodelmesissuemgmt              -13098
#define libtcsoamodelnx0tcin                  -13099

/*SOA Service libraries.*/
#define libtcsoaadministration                  -13101
#define libtcsoaadministrationstrongmngd        -13102
#define libtcsoaadministrationstrong            -13103

#define libtcsoaai                              -13106
#define libtcsoaaistrongmngd                    -13107
#define libtcsoaaistrong                        -13108

#define libtcsoaallocations                     -13111
#define libtcsoaallocationsstrongmngd           -13112
#define libtcsoaallocationsstrong               -13113

#define libtcsoaasbuilt                         -13116
#define libtcsoaasbuiltstrongmngd               -13117
#define libtcsoaasbuiltstrong                   -13118

#define libtcsoaauthorizeddataaccess            -13121
#define libtcsoaauthorizeddataaccessstrongmngd  -13122
#define libtcsoaauthorizeddataaccessstrong      -13123

#define libtcsoabom                             -13126
#define libtcsoabomstrongmngd                   -13127
#define libtcsoabomstrong                       -13128

#define libtcsoabusinessmodeler                 -13131
#define libtcsoabusinessmodelerstrongmngd       -13132
#define libtcsoabusinessmodelerstrong           -13133

#define libtcsoacad                             -13136
#define libtcsoacadstrongmngd                   -13137
#define libtcsoacadstrong                       -13138

#define libtcsoacalendarmanagement              -13141
#define libtcsoacalendarmanagementstrongmngd    -13142
#define libtcsoacalendarmanagementstrong        -13143

#define libtcsoachangemanagement                -13146
#define libtcsoachangemanagementstrongmngd      -13147
#define libtcsoachangemanagementstrong          -13148

#define libtcsoaclassification                  -13151
#define libtcsoaclassificationstrongmngd        -13152
#define libtcsoaclassificationstrong            -13153

#define libtcsoacoretypes                       -13155            /* Still used */
#define libtcsoacore                            -13156
#define libtcsoacorestrongmngd                  -13157
#define libtcsoacorestrong                      -13158

#define libtcsoadocumentmanagement              -13161
#define libtcsoadocumentmanagementstrongmngd    -13162
#define libtcsoadocumentmanagementstrong        -13163

#define libtcsoagdis                            -13166
#define libtcsoagdisstrongmngd                  -13167
#define libtcsoagdisstrong                      -13168

#define libtcsoaglobalmultisite                 -13171
#define libtcsoaglobalmultisitestrongmngd       -13172
#define libtcsoaglobalmultisitestrong           -13172

#define libtcsoaimportexport                    -13176
#define libtcsoaimportexportstrongmngd          -13177
#define libtcsoaimportexportstrong              -13178

#define libtcsoamanufacturing                   -13181
#define libtcsoamanufacturingstrongmngd         -13182
#define libtcsoamanufacturingstrong             -13183

#define libtcsoamrocore                         -13186
#define libtcsoamrocorestrongmngd               -13187
#define libtcsoamrocorestrong                   -13188

#define libtcsoamultisite                       -13191
#define libtcsoamultisitestrongmngd             -13192
#define libtcsoamultisitestrong                 -13193

#define libtcsoaproductionmanagement            -13196
#define libtcsoaproductionmanagementstrongmngd  -13197
#define libtcsoaproductionmanagementstrong      -13198

#define libtcmicroservicesutils                 -13199

#define libtcsoaprojectmanagementtypes          -13200    /* Still used*/
#define libtcsoaprojectmanagement               -13201
#define libtcsoaprojectmanagementstrongmngd     -13202
#define libtcsoaprojectmanagementstrong         -13203

#define libtcsoaquery                           -13206
#define libtcsoaquerystrongmngd                 -13207
#define libtcsoaquerystrong                     -13208

#define libtcsoardv                             -13211
#define libtcsoardvstrongmngd                   -13212
#define libtcsoardvstrong                       -13213

#define libtcsoareports                         -13216
#define libtcsoareportsstrongmngd               -13217
#define libtcsoareportsstrong                   -13218

#define libtcsoarequirementsmanagement          -13221
#define libtcsoarequirementsmanagementstrongmngd -1322
#define libtcsoarequirementsmanagementstrong    -13223

#define libtcsoastructuremanagement             -13226
#define libtcsoastructuremanagementstrongmngd   -13227
#define libtcsoastructuremanagementstrong       -13228

#define libtcsoatranslation                     -13231
#define libtcsoatranslationstrongmngd           -13232
#define libtcsoatranslationstrong               -13233

#define libtcsoautest                           -13236
#define libtcsoauteststrongmngd                 -13237
#define libtcsoauteststrong                     -13238

#define libtcsoavalidation                      -13241
#define libtcsoavalidationstrongmngd            -13242
#define libtcsoavalidationstrong                -13243

#define libtcsoavendormanagement                -13246
#define libtcsoavendormanagementstrongmngd      -13247
#define libtcsoavendormanagementstrong          -13248

#define libtcsoavisualization                   -13251
#define libtcsoavisualizationstrongmngd         -13252
#define libtcsoavisualizationstrong             -13253

#define libtcsoawireharness                     -13256
#define libtcsoawireharnessstrongmngd           -13257
#define libtcsoawireharnessstrong               -13258

#define libtcsoaworkflow                        -13261
#define libtcsoaworkflowstrongmngd              -13262
#define libtcsoaworkflowstrong                  -13263

#define libbase_utils                           -13264
#define libschmgt_bridge                        -13265

#define libtcsoaconfiguration                   -13267
#define libtcsoaconfigurationstrongmngd         -13268
#define libtcsoaconfigurationstrong             -13269

#define libmes                                  -13270
#define libcmtmesdispatch                       -13271
#define libmesbvr                               -13272

#define libtcsoames                             -13274
#define libtcsoamesstrongmngd                   -13275
#define libtcsoamesstrong                       -13276

#define libsharedcachetypes                     -13277
#define libsharedcache                          -13278

#define libai                                   -13280
#define libpie                                  -13281

#define libfnd0collabctxtest                    -13282

#define libtcsoadiagramming                     -13291
#define libtcsoadiagrammingstrongmngd           -13292
#define libtcsoadiagrammingstrong               -13293

/*Entries for cdm0contractmanagement*/
#define libcdm0contractmanagement               -13294
#define libcdm0contractmanagementdispatch       -13295

#define libciv0soacontmgmts1000d40strong        -13297
#define libciv0soacontmgmts1000d40strongmngd    -13298
#define libciv0soacontmgmts1000d40native        -13299

#define libtrv                                  -13300

#define libsas0soasvcautoscheduling             -13301
#define libsas0soasvcautoschedulingstrongmngd   -13302
#define libsas0soasvcautoschedulingtrong        -13303

#define libnxc0soatcincpdstrong                 -13304
#define libnxc0soatcincpdstrongmngd             -13305
#define libnxc0tcincpd                          -13306

/* Entries for Program Planning module*/
#define libprg0programinfra                     -13307
#define libprg1programplanningapp               -13308

#define libibom                                 -13309

#define libtesttie                              -13310
#define libxformer                              -13311
#define libFgc0cm4g                             -13320

#define libCAE0SimulationProcessManagement      -13321
#define libcaedispatch                          -13322
#define libcae0soamodelsimproc                  -13323
#define libcae0soamodelsimprocmngd              -13324

#define libsaservices                           -13325
#define libkeymanagerclient                     -13326

/* val0nxvalidation */
#define libval0soanxvalidationstrong            -13331
#define libval0soanxvalidationstrongmngd        -13332
#define libVal0nxvalidation                     -13333
#define libval0nxvalidationdispatch             -13334
#define libval0soanxvalidation                  -13335
#define libval0soamodelnxvalidation             -13336
#define libval0soamodelnxvalidationmngd         -13337

#define libFnd0Mrm                              -13338

#define libCtm0Callbacks                        -13339

/* bhv0branchfoundation */
#define libbhv0branchfoundation                 -13340
#define libbhv0branchfoundationdispatch         -13341
#define libbhv0soabranchfoundation              -13342
#define libbhv0soabranchfoundationmngd          -13343
#define libbhv0soabranchfoundationstrong        -13344
#define libbhv0soabranchfoundationstrongmngd    -13345

/* Adavanced PLM Services Core (APSCore) libs */
#define libaps0apscore                          -13346
#define libaps0apscoredispatch                  -13347

/* lcm0liscm */
#define libLcm0liscm                            -13348

#define libfourdplanningdispatch                -13349
#define libpmg0cpmgmt                           -13350
#define libpmg0cpmgmtdispatch                   -13351
#define libpreviousxerces                       -13352

/* Office Online */
#define liboo1soaofficeonline                   -13353
#define liboo1soaofficeonlinestrong             -13354
#define liboo1soaofficeonlinestrongmngd         -13355

/* les0lisesm */
#define libles0soamodellisesmmngd               -13356
#define libles0soamodellisesm                   -13357

/* cpd0mmv */
#define libcpd0mmv                              -13358

/*  Entries for Fastener Management  */
#define libFnd0FastenerMgmt                     -13359
#define libFnd0FastenerMgmtBvr                  -13360

/* esw0esmgmt */
#define libesw0soamodelesmgmt                   -13361
#define libesw0soamodelesmgmtmngd               -13362

/* cp0composites */
#define libcp0composites                        -13363
#define libcp0compositesdispatch                -13364
#define libcp0soamodelcomposites                -13365
#define libcp0soamodelcompositesmngd            -13366

/* Lis0ldfepm */
#define libLis0ldfepm                           -13367
/* Office Online Encryption */
#define liboo1encryption                        -13368

/* mdl0mmvconfigsolver */
#define libmdl0mmvconfigsolver                  -13369
/* Soa library entry for cdm0contractmanagement */
#define libcdm0soacontractmanagement            -13370

/* smc0soastructuremanagement */
#define libsmc0soastructuremanagement           -13371
#define libsmc0soastructuremanagementstrong     -13372
#define libsmc0soastructuremanagementstrongmngd -13373

/* Order Management (ord0) */
#define libOrd0ordermanagement                  -13374
#define libord0ordermanagementdispatch          -13375
#define libord0soamodelordermanagement          -13376
#define libord0soamodelordermanagementmngd      -13377

/* Advanceplanner */
#define libAp0advanceplanner                    -13378
#define libap0advanceplannerdispatch            -13379

/* Intosite */
#define libins0intosite                         -13380

/* Target Management (tgm0) */
#define libtgm0targetmgmt                       -13381
#define libtgm0targetmgmtdispatch               -13382

/* libFnd0Participant */
#define libFnd0Participant                      -13383

/* mdl0utestutil */
#define libmdl0utestutil                        -13384

/* Quality Center Base */
#define libQc0qualitybase                       -13385
#define libqc0qualitycenterbasedispatch         -13386
#define libqc0soamodelqualitycenterbase         -13387
#define libqc0soamodelqualitycenterbasemngd     -13388

/* Social Integration Service */
#define libsis0socialint                        -13389

#define libfnd0soaparticipant                   -13390
#define libfnd0soaparticipantstrongmngd         -13391
#define libfnd0soaparticipantstrong             -13392

/* Capital Asset Lifecycle Management(Pdm0) */
#define libpdm0plantdatamgmt                    -13393
#define libpdm0plantdatamgmtdispatch            -13394
#define libpdm0soaplantdatamgmt                 -13395
#define libpdm0soaplantdatamgmtstrongmngd       -13396
#define libpdm0soaplantdatamgmtstrong           -13397
#define libpdm0soamodelplantdatamgmt            -13398
#define libpdm0soamodelplantdatamgmtmngd        -13399

/* Parameter Management */
#define libAtt0attrtargetmgmt                   -13400
#define libatt0attrtargetmgmtdispatch           -13401
#define libatt0soaattrtargetmgmt                -13402
#define libatt0soaattrtargetmgmtstrong          -13403
#define libatt0soaattrtargetmgmtstrongmngd      -13404
#define libatt0soamodelattrtargetmgmt           -13405
#define libatt0soamodelattrtargetmgmtmngd       -13406

/* Verification Request */
#define libCrt0ValidationContract               -13407
#define libcrt0validationcontractdispatch       -13408
#define libcrt0soavalidationcontract            -13409
#define libcrt0soavalidationcontractstrong      -13410
#define libcrt0soavalidationcontractstrongmngd  -13411
#define libcrt0soamodelvalidationcontract       -13412
#define libcrt0soamodelvalidationcontractmngd   -13413

#define libiav0verificationmanagement           -13414
#define libiav0verificationmanagementdispatch   -13415

/* Control Inspection Plan */
#define libCip0controlinspplan                  -13416
#define libcip0controlinspplandispatch          -13417

/* Social Integration Service - SOA libraries */
#define libsis0soasocialint                     -13418
#define libsis0soasocialintstrong               -13419
#define libsis0soasocialintstrongmngd           -13420

/* CAPA (cpa0capadamodel)*/
#define libCPA0capadatamodel                    -13421
#define libcpa0capadatamodeldispatch            -13422

/* Enginering View Management */
#define libevm0soamodelviewmgmt                 -13423
#define libevm0soamodelviewmgmtmngd             -13424
#define libevm0viewmgmtdispatch                 -13425
#define libEvm0ViewMgmt                         -13426

/* CAD BOM Alignment */
#define libFnd0entcba                           -13427

/* Realization and Change Management Interface */
#define libRzc0rlzcm                            -13428

/* val1cfgvalidation */
#define libval1cfgvalidationdispatch            -13429
#define libval1soacfgvalidationstrong           -13430
#define libval1soacfgvalidationstrongmngd       -13431
#define libval1soacfgvalidation                 -13432
#define libval1soamodelcfgvalidation            -13433
#define libval1soamodelcfgvalidationmngd        -13434
#define libVal1cfgvalidation                    -13435

/* ECAD MCAD (EDMD) Collaboration Service - SOA libraries */
#define libeda0soaedmdcollab                    -13436
#define libeda0soaedmdcollabstrong              -13437
#define libeda0soaedmdcollabstrongmngd          -13438

/* CSI */
#define libcsi0soacmsminterface                 -13439

/* Product Master Automation */
#define libPma0automation                       -13440

/* Cla0Classification - SOA library */
#define libcla0soaclassificationcommon          -13441

/* DSDashboard - Data Share Dashboard library */
#define libdsdashboard                          -13442

/* Feature Planning */
#define libcfp0featureplanning                  -13443
#define libcfp0featureplanningdispatch          -13444
#define libcfp0soafeatureplanning               -13445
#define libcfp0soamodelfeatureplanning          -13446
#define libcfp0soamodelfeatureplanningmngd      -13447

/* Weight and Balance Management */
#define libWnb0weightandbalance                 -13448
#define libwnb0weightandbalancedispatch         -13449

/* ObjectDataServices library */
#define libods0soaobjectdataservices            -13450
#define libods0objectdataservices               -13451
#define libods0objectdataservicesdispatch       -13452

/* Partition asynchronous API */
#define libPtn0PartitionAsync                   -13453

/* mea0fpam */
#define libmea0soamodelmea0fpam                 -13454
#define libmea0soamodelmea0fpammngd             -13455

/* Product Configurator Feature Planning */
#define libpfp0featureplanning                  -13456

#define libpfp0featureplanningdispatch          -13457
#define libpfp0soafeatureplanning               -13458
/* clsjsonhelper */
#define libclsjsonhelper                        -13459

/* Mfg Validation Samples*/
#define libmfgvalidationsamples                 -13460


#endif /*COMMON_LIBRARY_INDICATORS_H_INCLUDED*/
