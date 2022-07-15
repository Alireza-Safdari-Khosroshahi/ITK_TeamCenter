
//int CT4populateValuesonIR(METHOD_message_t* msg, va_list args)
//{
//	TC_write_syslog("in CT4populateValuesonIR post action\n");
//	/*tag_t itemtag = va_arg(args, tag_t);
//	const char* revid = va_arg(args, const char*);
//	tag_t* revtag = va_arg(args, tag_t*);
//
//	int prefcount;
//	char** prefvalues = NULL;
//	char* obj_type = NULL;
//	int retcode = PREF_ask_char_values("CT4_CLASSIFICATION_CLASS", &prefcount, &prefvalues);
//	retcode = AOM_ask_value_string(*revtag, "object_type", &obj_type);
//	TC_write_syslog("obj_type  = %s\n", obj_type);
//	for (int i = 0; i < prefcount; i++)
//	{
//		TC_write_syslog("prefvalues[%d]  = %s\n", i, prefvalues[i]);
//		char* pch = strtok(prefvalues[i], "=");
//
//
//		if (pch != NULL)
//		{
//			TC_write_syslog("%s  = %s\n", obj_type, pch);
//			if (strcmp(obj_type, pch) == 0)
//			{
//
//				pch = strtok(NULL, "=");
//				if (pch != NULL)
//				{
//					TC_write_syslog("class value = % s\n", pch);
//
//
//					retcode = AOM_refresh(*revtag, true);
//
//					if (retcode == ITK_ok)
//						retcode = AOM_set_value_string(*revtag, "ct4_class_for_name", pch);
//
//					if (retcode == ITK_ok)
//						retcode = AOM_save_without_extensions(*revtag);
//
//					AOM_refresh(*revtag, false);
//				}
//			}
//		}
//	}*/
//return 0;
//
//}

//
//int CT4ClassificationObjOnMod(METHOD_message_t* msg, va_list args)
//{
//	TC_write_syslog("in CT4ClassificationObjOnMod iman save START\n");
//
//	/*int retcode = ITK_ok;
//	
//	tag_t relation = va_arg(args, tag_t);
//	logical isnew = va_arg(args, logical);
//	tag_t itemrev = NULL_TAG;
//	tag_t classficationobj = NULL_TAG;
//	retcode = GRM_ask_primary(relation, &itemrev);
//	retcode = GRM_ask_secondary(relation, &classficationobj);
//
//	char* class_name_attr;
// 
//	retcode = AOM_ask_value_string(itemrev, "ct4_class_for_name", &class_name_attr);
//	TC_write_syslog("obj_type  = %s\n", class_name_attr);
//
//	retcode = UpdatepropwithClasification(itemrev, classficationobj, class_name_attr, "CLASSIFICATIONOPEXT");
//	*/
//
//	TC_write_syslog("in CT4ClassificationObjOnMod iman save END\n");
//	return 0;
//}





//int CT4ClasspropUpdateext(METHOD_message_t* msg, va_list args)
//{
//	TC_write_syslog("in CT4ClasspropUpdateext prop action START");
//
//	int retcode = ITK_ok;
//	/*tag_t itemrevtag;
//	tag_t prop_tag = va_arg(args, tag_t);
//	const char* newpropvalue = va_arg(args, const char*);
//
//
//	TC_write_syslog("newpropvalue  =  %s\n", newpropvalue);
//
//	METHOD_PROP_MESSAGE_OBJECT(msg, itemrevtag);
//	tag_t relation_type = NULL_TAG;
//	retcode = GRM_find_relation_type("IMAN_classification", &relation_type);
//
//	int count = 0;
//	tag_t* objects = NULL;
//
//	if (retcode == 0)
//		retcode = GRM_list_secondary_objects_only(itemrevtag, relation_type, &count, &objects);
//
//		TC_write_syslog("Secondary objects count  =  %d\n", count);
//		if (count > 0)
//		{
//			tag_t classification_obj = objects[0];
//			retcode = UpdatepropwithClasification(itemrevtag, classification_obj, (char *)newpropvalue,"PROPEXT");
//		}
//		*/
//		TC_write_syslog("in CT4ClasspropUpdateext prop action END");
//
//	return 0;
//}


//int CT4IcmRunPropGetterPostAct(METHOD_message_t* msg, va_list args)
//{
//
//	TC_write_syslog("LEAVE - CT4IcmRunPropGetterPostAct");
//
//	return 0;
//
//}
//
//int CT4IcmRunPropSetterPostAct(METHOD_message_t* /*msg*/, va_list args)
//{
//
//	TC_write_syslog("LEAVE - CT4IcmRunPropSetterPostAct");
//	return 0;
//
//}
//
//
//
//
//int CT4IcmRunPropSetterPreAct(METHOD_message_t* msg, va_list args)
//{
//
//	TC_write_syslog("LEAVE - CT4IcmRunPropSetterPreAct");
//	return 0;
//
//}