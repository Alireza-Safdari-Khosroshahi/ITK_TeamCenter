//@<COPYRIGHT>@
//==================================================
//Copyright $2022.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//@<COPYRIGHT>@

/* 
 * @file 
 *
 *   This file contains the implementation for the Extension CT4_ClassificationforModul
 *
 */

#include "CT4_ClassificationObj.hxx"
std::map<tag_t, GRM_relation_t> gRelationInfoMap;

//This Extension is triggered during Classification object creation 
//BO: IMAN_Classification Operation:GRM_Create
int CT4_ClassificationforModul(METHOD_message_t* msg, va_list args)
{
	TC_write_syslog("in calssification post action");

	int retcode = ITK_ok;
	tag_t primary_tag = va_arg(args, tag_t);
	tag_t secondary_tag = va_arg(args, tag_t);
	tag_t objectTypeClassId = NULLTAG;
	tag_t objectClassId = NULLTAG;
	char* szCFClassId = NULL;
	char* szCFViewId = NULL;
	logical lSubClass = FALSE;

	char* slanenge = NULL;
	char* scontainer = NULL;


	int prefcount;
	char** prefvalues = NULL;
	char* obj_type = NULL;
	bool isvalidrev = false;
	retcode = PREF_ask_char_values("CT4_CLASSIFICATION_CLASS", &prefcount, &prefvalues);
	retcode = AOM_ask_value_string(primary_tag, "object_type", &obj_type);
	TC_write_syslog("obj_type  = %s\n", obj_type);
	if(obj_type != NULL)
	for (int i = 0; i < prefcount; i++)
	{
		TC_write_syslog("prefvalues[%d]  = %s\n", i, prefvalues[i]);
		if (strcmp(obj_type, prefvalues[i]) == 0)
		{
			isvalidrev = true;
		}
	}

	if (isvalidrev == false) {
		TC_write_syslog("Revision type= %s not valid\n", obj_type);
		return ITK_ok;
	}

	retcode = POM_class_id_of_class("ItemRevision", &objectTypeClassId);

	if (retcode == ITK_ok)
		retcode = POM_class_of_instance(primary_tag, &objectClassId);

	if (retcode == ITK_ok)
		retcode = POM_is_descendant(objectTypeClassId, objectClassId, &lSubClass);

	if (objectClassId == objectTypeClassId || lSubClass)
	{
		tag_t tSmlb0 = NULLTAG;
		char* pcUserData = NULL;
		retcode = ICS_ask_cid_sid_of_classification_obj(secondary_tag, &szCFClassId, &szCFViewId);
		TC_write_syslog("class id: %s", szCFClassId);

		retcode = getSmlb0FromCid((const char*)szCFClassId, tSmlb0);
		TC_write_syslog("tSmlb0  = %d\n", tSmlb0);
		if (retcode == ITK_ok && tSmlb0 != NULLTAG) {

				retcode = AOM_ask_value_string(tSmlb0, "ext_1", &pcUserData);
				if (retcode == ITK_ok)
					TC_write_syslog("ext_1  = %s\n", pcUserData);
				else
					TC_write_syslog("ext_1 is null \n");
		}
	

		if (retcode == ITK_ok)
		{
			TC_write_syslog("obj_type  = %s\n", pcUserData);
			retcode = UpdatepropwithClasification(primary_tag, secondary_tag, pcUserData, "CLASSIFICATIONOPEXT");
		}

		if(pcUserData!= NULL)
			MEM_free(pcUserData);

	}
	TC_write_syslog("in calssification post action END");
	return 0;

}



int getSmlb0FromCid(const char* cid, tag_t &tSmlbo) {

	int retcode = ITK_ok;
	int iRows = 0;
	int iCols = 0;
	void*** ppvSml = NULL;
	const char* select_attr_list[] = { "puid" };
	const  char** cidval = &cid;

	TC_write_syslog("Entered getSmlb0FromCid\n" );


	char** entries = NULL;
	char** values = NULL;
	int n_entries = 1;
	tag_t tag_query;
	int num_found;
	tag_t* tag_query_result = NULL;

	entries = (char**)MEM_alloc(n_entries * sizeof(char*));
	values = (char**)MEM_alloc(n_entries * sizeof(char*));

	entries[0] = (char*)MEM_alloc(10);
	strcpy(entries[0], "cid");

	values[0] = (char*)MEM_alloc(strlen(cid) + 1);
	strcpy(values[0], cid);


	if (retcode == ITK_ok)
		retcode  = QRY_find2("CT4_classificationStClassID", &tag_query);
	

	if (retcode == ITK_ok)
	{
		retcode = QRY_execute(tag_query, n_entries, entries, values, &num_found, &tag_query_result);
		TC_write_syslog("Number of storage classes = %d\n", num_found);
	}
	
	if ((retcode == ITK_ok) && (num_found > 0))
	{
		tSmlbo = tag_query_result[0];
		TC_write_syslog("Storage Class tag = %d\n", tSmlbo);
	}

	TC_write_syslog("Exited getSmlb0FromCid\n");

	return retcode;

}


int UpdatepropwithClasification(tag_t itemrev, tag_t classification, char* class_name, string exttype)
{
	TC_write_syslog("in UpdateDescwithClasification START");

	int retcode = 0;

	int nAttributes;           
	char** attributeNames;          
	char** attributeValues;        

	tag_t view;                  
	int* unctNumbers;            
	int* unctFormats;            
		char** units;                 

	retcode =  ICS_describe_classification_object(classification, &view, &nAttributes, &unctNumbers, &unctFormats, &attributeNames, &attributeValues, &units);
	std::string sDesc = "";
	char* name = NULL;
	retcode = AOM_ask_value_string(itemrev, "object_name", &name);
	
	if (class_name != NULL && retcode == 0) {
		TC_write_syslog("obj_type  = %s\n", class_name);
		vector<int> classes;
		char* pch = strtok(class_name, ",");
		while (pch != NULL)
		{
			classes.push_back(atoi(pch));
			pch = strtok(NULL, ",");
		}
		string IRname = "";
		if (name != NULL)
		{
			IRname.assign(name);
			if (strlen(name) > 0)
			{
				char* pchname = strtok(name, "~");
				if (pchname != NULL)
					IRname.assign(pchname);

			}
		}

		sDesc.append(IRname);
		sDesc.append("~");
		for (int ii = 0; ii < nAttributes; ii++)
		{

			TC_write_syslog("unctNumbers = %d \n attributeNames= %s \n attributeValues =%s\n", unctNumbers[ii], attributeNames[ii], attributeValues[ii]);
			char* vale = NULL; char* key_lov_name; 	int options;
			int n_lov_entries; char** lov_keys; char** lov_values;
			logical* deprecated_staus; char* owning_site; int n_shared_sites;
			char** shared_sites;

			int id = unctFormats[ii];
			for (int kk = 0; kk < classes.size(); kk++)
			{
				TC_write_syslog("%d = %d\n", id, -classes[kk]);
				if (id == -classes[kk])
				{

					char idstr[100];
					sprintf(idstr, "%d", id);
					TC_write_syslog("idstr = %s\n", idstr);

					retcode =ICS_keylov_get_keylov(idstr, &key_lov_name, &options, &n_lov_entries, &lov_keys, &lov_values, &deprecated_staus, &owning_site, &n_shared_sites, &shared_sites);
					TC_write_syslog("key_lov_name %s\n", key_lov_name);

					for (int jj = 0; jj < n_lov_entries; jj++)
					{
						if (strcmp(attributeValues[ii], lov_keys[jj]) == 0)
						{
							TC_write_syslog("lov_keys %s = %s\n", lov_keys[jj], lov_values[jj]);
							sDesc.append(lov_values[jj]);
							int k = ii + 1;
							if (k < nAttributes) {
								sDesc.append("~");
							}
						}

					}
				}
			}

		}
	}

	//ICS_class_attr_ask_dep_keylovs
	if(exttype.compare("CLASSIFICATIONOPEXT") == 0)
		retcode = AOM_refresh(itemrev, true);

	
	char lastCharacter = sDesc.back();
	if(lastCharacter == '~')
		sDesc = sDesc.substr(0, sDesc.length() - 1);

	if (retcode == ITK_ok)
		retcode = AOM_set_value_string(itemrev, "object_name", sDesc.c_str());

	if (retcode == ITK_ok)
		retcode = AOM_save_without_extensions(itemrev);

	if (exttype.compare("CLASSIFICATIONOPEXT") == 0)
		retcode = AOM_refresh(itemrev, false);

	TC_write_syslog("in UpdateDescwithClasification prop action END");

	return retcode;
}




//This Extension is triggered during Classification object deletion 
//BO: IMAN_Classification Operation:IMAN+delete   Condition: Post-Action 
int CT4ClassificationObjDel_PostAct(METHOD_message_t* msg, va_list args)
{

	int retcode = ITK_ok;
	tag_t tPrimaryObj = NULLTAG;
	tag_t tSecondaryObj = NULLTAG;
	tag_t tRelationType = NULLTAG;
	tag_t tRelation = NULLTAG;

	TC_write_syslog("ENTER - Method_delete_classification");

	tRelation = msg->object_tag;




	

	if (gRelationInfoMap.find(tRelation) != gRelationInfoMap.end())
	{
		tPrimaryObj = gRelationInfoMap[tRelation].primary;
		tSecondaryObj = gRelationInfoMap[tRelation].secondary;
		tRelationType = gRelationInfoMap[tRelation].relation_type;

		TC_write_syslog("Relation info retrieved successfully from map. (Relation %d)", tRelation);
	}

	if (tPrimaryObj != NULLTAG)
	{


		int prefcount;
		char** prefvalues = NULL;
		char* obj_type = NULL;
		bool isvalidrev = false;
		retcode = PREF_ask_char_values("CT4_CLASSIFICATION_CLASS", &prefcount, &prefvalues);
		retcode = AOM_ask_value_string(tPrimaryObj, "object_type", &obj_type);
		TC_write_syslog("obj_type  = %s\n", obj_type);
		if (obj_type != NULL)
			for (int i = 0; i < prefcount; i++)
			{
				TC_write_syslog("prefvalues[%d]  = %s\n", i, prefvalues[i]);
				if (strcmp(obj_type, prefvalues[i]) == 0)
				{
					isvalidrev = true;
				}
			}

		if (isvalidrev == false) {
			TC_write_syslog("Revision type= %s not valid\n", obj_type);
			return ITK_ok;
		}



		char* pcObjName = NULL;

		retcode = AOM_ask_value_string(tPrimaryObj, "object_name", &pcObjName);
		if (pcObjName != NULL && retcode == ITK_ok)
		{
			TC_write_syslog("pcObjName %s", pcObjName);

			int nCount = 0;
			char** spStrings = NULL;

			if (strlen(pcObjName) > 0)
			{
				char* pchname = strtok(pcObjName, "~");
				if (pchname != NULL)
					TC_write_syslog("spStrings[0] %s", pchname);

				retcode = AOM_refresh(tPrimaryObj, true);
				if (retcode == ITK_ok)
				{
					retcode = AOM_set_value_string(tPrimaryObj, "object_name", pchname);
					retcode = AOM_save_with_extensions(tPrimaryObj);
					retcode =  AOM_refresh(tPrimaryObj, false);
				}
			}
			//if (nCount > 0)
			//	SAFE_SM_FREE_ARRAY(nCount, spStrings);
		}

		if(pcObjName!=NULL)
			MEM_free(pcObjName);
	}

	TC_write_syslog("LEAVE - Method_save_relation_info");
	return 0;

}


//This Extension is triggered during Classification object deletion 
//BO: IMAN_Classification Operation:IMAN_delete   Condition: Pre-Condition
int CT4ClassificationObjDel_PreCond(METHOD_message_t* msg, va_list args)
{

	int	retcode = ITK_ok;
	tag_t tPrimaryObj = NULLTAG;
	tag_t tSecondaryObj = NULLTAG;
	tag_t tRelType = NULLTAG;
	tag_t tRelation = NULLTAG;

	TC_write_syslog("ENTER - Method_save_relation_info");

	tRelation = msg->object_tag;

	GRM_ask_primary(tRelation, &tPrimaryObj);
	GRM_ask_secondary(tRelation, &tSecondaryObj);
	GRM_ask_relation_type(tRelation, &tRelType);


	int prefcount;
	char** prefvalues = NULL;
	char* obj_type = NULL;
	bool isvalidrev = false;
	retcode = PREF_ask_char_values("CT4_CLASSIFICATION_CLASS", &prefcount, &prefvalues);
	retcode = AOM_ask_value_string(tPrimaryObj, "object_type", &obj_type);
	TC_write_syslog("obj_type  = %s\n", obj_type);
	if (obj_type != NULL)
		for (int i = 0; i < prefcount; i++)
		{
			TC_write_syslog("prefvalues[%d]  = %s\n", i, prefvalues[i]);
			if (strcmp(obj_type, prefvalues[i]) == 0)
			{
				isvalidrev = true;
			}
		}

	if (isvalidrev == false) {
		TC_write_syslog("Revision type= %s not valid\n", obj_type);
		return ITK_ok;
	}






	gRelationInfoMap[tRelation].the_relation = tRelation;
	gRelationInfoMap[tRelation].primary = tPrimaryObj;
	gRelationInfoMap[tRelation].secondary = tSecondaryObj;
	gRelationInfoMap[tRelation].relation_type = tRelType;
	gRelationInfoMap[tRelation].user_data = NULLTAG;
	
	TC_write_syslog("LEAVE - Method_save_relation_info");

	return 0;
}


int CT4populateValuesonIR(METHOD_message_t* msg, va_list args)
{
	TC_write_syslog("in CT4populateValuesonIR post action\n");

	tag_t itemtag = va_arg(args, tag_t);
	const char* revid = va_arg(args, const char*);
	tag_t* revtag = va_arg(args, tag_t*);
	char* propval = NULL;
	
	int retcode = AOM_ask_value_string(*revtag, "ct4_SE_mass", &propval);

	if(propval != NULL)
	{ 
		TC_write_syslog("\n before propval -------->%s", propval);
		string semassval = propval;
		if (semassval.length() > 0)
		{
			semassval.assign(ReplaceString(semassval, ",", "."));
			if (semassval.length() > 0)
				strcpy(propval, semassval.c_str());
		}

		TC_write_syslog("\n after propval -------->%s", propval);


		retcode = AOM_refresh(*revtag, true);
		if(retcode == ITK_ok)
			retcode = SetMassvalue(propval, *revtag);

		if (retcode == ITK_ok)
			retcode = AOM_refresh(*revtag, false);
	}

return retcode;

}


int CT4ExtractBOMDataOnSolVar_Save(METHOD_message_t* msg, va_list args)
{
	TC_write_syslog("CT4ExtractBOMDataOnSolVar_Save ENTERED\n");

	/*tag_t primary_tag = va_arg(args, tag_t);
	tag_t secondary_tag = va_arg(args, tag_t);

	TC_write_syslog("primary_tag = %d\n", primary_tag);
	TC_write_syslog("secondary_tag = %d\n", secondary_tag);


	char* obj_type = NULL;
	bool isvalidrev = false;
	
	int retcode = AOM_ask_value_string(primary_tag, "object_type", &obj_type);
	TC_write_syslog("obj_type  = %s\n", obj_type);


	char* itemid = NULL;
	 retcode = AOM_ask_value_string(primary_tag, "item_id", &itemid);
	TC_write_syslog("item_id  = %s\n", obj_type);


	TC_write_syslog("CT4ExtractBOMDataOnSolVar_Save EXIT\n");*/
	return 0;

}

int CT4ExtractBOMDataOnSolVar_Create(METHOD_message_t* msg, va_list args)
{

	TC_write_syslog("CT4ExtractBOMDataOnSolVar_create ENTERED\n");

	/*tag_t BOMhundreditem = va_arg(args, tag_t);
	tag_t BOMOnefiftyitem = va_arg(args, tag_t);

	TC_write_syslog("BOMhundreditem = %d\n", BOMhundreditem);
	TC_write_syslog("BOMOnefiftyitem = %d\n", BOMOnefiftyitem);

	char* obj_type = NULL;
	char* itemid100 = NULL;

	int retcode = AOM_ask_value_string(BOMhundreditem, "object_type", &obj_type);
	TC_write_syslog("obj_type  = %s\n", obj_type);
	retcode = AOM_ask_value_string(BOMhundreditem, "item_id", &itemid100);
	TC_write_syslog("item_id  = %s\n", itemid100);

	//tag_t item_tag = null_tag;
	tag_t window = null_tag;
	tag_t rule = null_tag;
	tag_t top_line = null_tag;
	tag_t* tags_found = NULL;


	BOM_create_window(&window);
	CFM_find("Latest Working", &rule); //Find Revision Rule 
	BOM_set_window_config_rule(window, rule);//Set Revision Rule 
  	BOM_set_window_pack_all(window, true);
	BOM_set_window_top_line(window, NULL_TAG, BOMhundreditem, null_tag, &top_line);


	printrecursivebom(top_line, BOMhundreditem, 0, itemid100);
	TC_write_syslog("CT4ExtractBOMDataOnSolVar_create EXIT\n");
	*/
	return 0;

}



static void printrecursivebom(tag_t line, tag_t Parent, int depth, char* req_item,char * VarRuleVal)
{
	int n = 0;
	int k = 0;
	int attribute;

	tag_t* children;
	tag_t    value;
	tag_t latestrev = NULL_TAG;

	depth++;


	latestrev = Parent;	

	TC_write_syslog("\n\n\t\t printrecursivebom\n");

	BOM_line_ask_child_lines(line, &n, &children);
	TC_write_syslog("\n No:of Child Parts are -------->%d\n", n);
	TC_write_syslog("\nDepth value is -------->%d\n", depth);

	for (k = 0; k < n; k++)
	{
		//get the revision from bomline
		

		int attribute_SolVar;
		char* SolVarVal = NULL;
		int retCode = BOM_line_look_up_attribute("bl_rev_Smc0SolutionVariantSource", &attribute_SolVar);
		if (retCode == ITK_ok)
			retCode = BOM_line_ask_attribute_string(children[k], attribute_SolVar, &SolVarVal);

		if (retCode == ITK_ok && SolVarVal != NULL) {
			TC_write_syslog("\n\n\n Sol Variant value is  :: %s\n", SolVarVal);
			//if (tc_strcmp(SolVarVal, "") != 0)
			{
				int attribute_PosCor;
				char* PosCorValinp = NULL;
				int retCode = BOM_line_look_up_attribute("bl_rev_ct4_PositionCorrection", &attribute_PosCor);
				if (retCode == ITK_ok)
					retCode = BOM_line_ask_attribute_string(children[k], attribute_PosCor, &PosCorValinp);
				TC_write_syslog("\n\n\n old PositionCorrection is  :: %s\n", PosCorValinp);
				
				string NewPosCorVal = "";
				NewPosCorVal = getPosCorbasedVarAttr(PosCorValinp, VarRuleVal);


				TC_write_syslog("\n\n\n New PositionCorrection is  :: %s\n", NewPosCorVal.c_str());
				char* PosCorVal = NULL;
				PosCorVal = (char*)malloc(sizeof(char) * NewPosCorVal.length());
				strcpy(PosCorVal, NewPosCorVal.c_str());

				if (retCode == ITK_ok && PosCorVal != NULL && VarRuleVal != NULL)
				{
					TC_write_syslog("\n\n\n PositionCorrection is  :: %s\n", PosCorVal);
					if (tc_strcmp(PosCorVal, "") != 0)
					{
						int attribute_matrix;
						char* MatrixVal = NULL;
						retCode = BOM_line_look_up_attribute("bl_plmxml_occ_xform", &attribute_matrix);
						if (retCode == ITK_ok) {
							retCode = BOM_line_ask_attribute_string(children[k], attribute_matrix, &MatrixVal);
							if (retCode == ITK_ok && MatrixVal != NULL) {
								TC_write_syslog("\n\n\n Matrix is  :: %s\n", MatrixVal);

								char* updatedMatrixval = NULL;
								string updatedmatrix = getUpdatedmatrixval(PosCorVal, MatrixVal, &updatedMatrixval);
								TC_write_syslog("\n\n\n updated matrix is  :: %s\n", updatedmatrix.c_str());

								retCode = BOM_line_set_attribute_string(children[k], attribute_matrix, updatedmatrix.c_str());

							}
						}
					}
				}
			}
		}
		//printrecursivebom(children[k], line, depth, req_item);
	}
	TC_write_syslog("\n After Depth value is -------->%d\n", depth);
}


string getPosCorbasedVarAttr(char* PosCorVal, char* VarRuleVal  )
{

	char transfrom[MAXVAL][50];
	int index = 0;
	int index2 = 0;
	TC_write_syslog("\n getPosCorbasedVarAttr PosCorVal -------->%s", PosCorVal);
	TC_write_syslog("\n VarRuleVal -------->%s", VarRuleVal);

	if (PosCorVal != NULL)
	{
		char* pch = strtok(PosCorVal, " ");
		while (pch != NULL)
		{
			if (strlen(pch) > 0)
			{
				strcpy(transfrom[index], pch);
				index++;
			}
			pch = strtok(NULL, " ");
		}
	}

	char option[100][100];
	char val[100][100];
	
	string sVarRuleVal(VarRuleVal);
	std::vector<std::string> v;
	tokenize(sVarRuleVal, ']',v);

		for (string str : v) {
			if (strstr(str.c_str(), "=") != NULL)
			{
				TC_write_syslog("Opt val = %s\n", str.c_str());
				vector<string> vectOption;
				tokenize(str, ' ', vectOption);
				if (vectOption.size() >= 3)
				{
					TC_write_syslog("Opt  = %s\n", vectOption[0].c_str());
					TC_write_syslog("equal = %s\n", vectOption[1].c_str());
					TC_write_syslog("Opt val = %s\n", vectOption[2].c_str());
					strcpy(option[index2], vectOption[0].c_str());
					strcpy(val[index2], vectOption[2].c_str());
					index2++;
				}
				
			}
		}

	for (int ii = 0; ii < index2; ii++)
	{
		TC_write_syslog("Opt val = %s\n", option[ii]);
		TC_write_syslog("val = %s\n", val[ii]);
	}


	string modpositioncorrection = "";
	for (int ii = 0; ii < index; ii++)
	{
		TC_write_syslog("prop val = %s\n", transfrom[ii]);
		if (strcmp(transfrom[ii], "0") != 0)
		{
			bool found = false;
			for (int jj = 0; jj < index2; jj++)
			{
				if (strcmp(transfrom[ii], option[jj]) == 0)
				{
					modpositioncorrection.append(val[jj]);
					modpositioncorrection.append(" ");
					found = true;
					break;
				}
				
			}

			if (found == false)
			{
				modpositioncorrection.append(transfrom[ii]);
				modpositioncorrection.append(" ");
			}
		}
		else
		{
			modpositioncorrection.append("0");
			modpositioncorrection.append(" ");
		}
	}

	modpositioncorrection  = trim(modpositioncorrection);
	TC_write_syslog("prop val = %s\n", modpositioncorrection.c_str());

	return modpositioncorrection;
}

string getUpdatedmatrixval(char * PosCorVal, char*  MatrixVal, char **updatedMatrixval)
{
	int retcode = ITK_ok;
	int index = 0;
	double transfrom[MAXVAL];

	TC_write_syslog("\n PosCorVal -------->%s", PosCorVal);
	TC_write_syslog("\n MatrixVal -------->%s", MatrixVal);

	if(PosCorVal != NULL)
	{ 
		char *pch = strtok(PosCorVal," ");
		
		while (pch != NULL)
		{
			if (strlen(pch) > 0)
			{
				transfrom[index] = atof(pch);
				index++;
			}
			pch = strtok(NULL, " ");
		}
		
	}

	if (index != MAXVAL)
		return "";

	string updatedmatrix = "";
	if(index ==  MAXVAL)
	{ 
		TC_write_syslog("\n After Depth value is -------->%s %f  %f %f %f %f %f\n", MatrixVal, transfrom[0], 
																	transfrom[1], transfrom[2], transfrom[3], transfrom[4], transfrom[5]);

		ChangeMatrix chngmtx;
		string sMatrixVal(MatrixVal);
		 updatedmatrix = chngmtx.computeTransformationMatrix(sMatrixVal,
			transfrom[0], transfrom[1], transfrom[2],
			transfrom[3], transfrom[4], transfrom[5]);
	}

	TC_write_syslog("\n updatedmatrix -------->%s\n", updatedmatrix.c_str());

	return updatedmatrix;

}



std::string ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s) {
	return rtrim(ltrim(s));
}


int CT4_PopulateMassAttr_toMassUOM(METHOD_message_t* msg, va_list args)
{
	TC_write_syslog("CT4_PopulateMassAttr_toMassUOM ENTERED\n");

	tag_t proptag = va_arg(args, tag_t);
	char *propval = va_arg(args, char*);

	tag_t itemrev = NULL_TAG;
	METHOD_PROP_MESSAGE_OBJECT(msg, itemrev);


	int ifail = ITK_ok;
	if (propval != NULL)
	{
		TC_write_syslog("\n before propval -------->%s", propval);
		string semassval = propval;
		if (semassval.length() > 0)
		{
			semassval.assign(ReplaceString(semassval, ",", "."));
			if (semassval.length() > 0)
				strcpy(propval, semassval.c_str());
		}

		TC_write_syslog("\n after propval -------->%s", propval);

		ifail = SetMassvalue(propval, itemrev);
	}
	return ifail;

}


int SetMassvalue(char * propval, tag_t itemrev)
{
	int ifail = ITK_ok;
	if (propval != NULL)
	{
		TC_write_syslog("prop val = %s\n", propval);


		if (itemrev != NULL_TAG)
		{

			if (strlen(propval) == 0)
			{
				double num_double = 0.0;
				 ifail = AOM_set_value_double(itemrev, "ct4_mass", num_double);
				if (ifail == ITK_ok)
				{
					ifail = AOM_set_value_string(itemrev, "ct4_mass_unit", "");
					if (ifail == ITK_ok)
					{
						ifail = AOM_save_without_extensions(itemrev);
					}
				}

			}
			else
			{
				string mass;
				string UOM;
				char* pch = NULL;
				pch = strtok(propval, " ");
				if (pch != NULL)
				{
					mass.assign(pch);
					pch = strtok(NULL, " ");
					if (pch != NULL)
					{
						UOM.assign(pch);
						double num_double = std::stod(mass);
						int ifail = AOM_set_value_double(itemrev, "ct4_mass", num_double);
						if (ifail == ITK_ok)
						{
							ifail = AOM_set_value_string(itemrev, "ct4_mass_unit", UOM.c_str());
							if (ifail == ITK_ok)
							{
								ifail = AOM_save_without_extensions(itemrev);
							}
						}

					}

				}
			}
		}
	}

	return ifail;

}



int CT4ExtractBOMDataOnCC_Create(METHOD_message_t* msg, va_list args)
{
	TC_write_syslog("in CT4ExtractBOMDataOnCC_Create post action\n");

	
	tag_t BOMhundreditem = va_arg(args, tag_t);
	tag_t CC = va_arg(args, tag_t);

	TC_write_syslog("BOMhundreditem = %d\n", BOMhundreditem);
	TC_write_syslog("BOMOnefiftyitem = %d\n", CC);

	tag_t VarRuletag = NULL;
	int retCode2 = AOM_ask_value_tag(CC, "variant_rule", &VarRuletag);
	TC_write_syslog("\n ========1>varaint_rule tag  :: %d\n", VarRuletag);
	char* VarRuleVal = NULL;
	if (VarRuletag != NULL_TAG)
	{
		
		retCode2 = AOM_ask_value_string(VarRuletag, "cfg0VariantRuleText", &VarRuleVal);
		TC_write_syslog("\n  ========1>> VarRuletag retCode is  :: %d\n", retCode2);
		TC_write_syslog("\n ========1>>VarRuletag cfg0VariantRuleText on Variant rules  :: %s\n", VarRuleVal);
	


	
	char* obj_type = NULL;
	char* itemid100 = NULL;

	int retcode = AOM_ask_value_string(BOMhundreditem, "object_type", &obj_type);
	TC_write_syslog("obj_type  = %s\n", obj_type);
	retcode = AOM_ask_value_string(BOMhundreditem, "item_id", &itemid100);
	TC_write_syslog("item_id  = %s\n", itemid100);

	//tag_t item_tag = null_tag;
	tag_t window = null_tag;
	tag_t rule = null_tag;
	tag_t top_line = null_tag;
	tag_t* tags_found = NULL;


	BOM_create_window(&window);
	CFM_find("Latest Working", &rule); //Find Revision Rule 
	BOM_set_window_config_rule(window, rule);//Set Revision Rule 
	BOM_set_window_pack_all(window, true);
	BOM_set_window_top_line(window, NULL_TAG, BOMhundreditem, null_tag, &top_line);


	printrecursivebom(top_line, BOMhundreditem, 0, itemid100, VarRuleVal);
	TC_write_syslog("CT4ExtractBOMDataOnSolVar_create EXIT\n");
	}


	return 0;

}

void tokenize(std::string const& str, const char delim,
	std::vector<std::string>& out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}


std::string ReplaceString(std::string subject, const std::string& search,
	const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}