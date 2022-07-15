#include <ae/ae.h>
#include <ae/dataset.h>
#include <ae/datasettype.h>
#include <ae/nxsm.h>
#include <ecm/ecm.h>
#include <epm/epm.h>
#include <tc/folder.h>
#include <form/form.h>
#include <ict/ict_userservice.h>
#include <itk/mem.h>
#include <property/prop.h>
#include <property/prop_errors.h>
#include <property/prop_msg.h>
#include <stdarg.h>
#include <string.h>
#include <tc/emh.h>
#include <tc/emh_const.h>
#include <tc/tc.h>
#include <tccore/aom.h>
#include <tccore/aom_prop.h>
#include <tccore/custom.h>
#include <tccore/item.h>
#include <tccore/item_errors.h>
#include <tccore/method.h>
#include <tccore/tctype.h>
#include <tccore/workspaceobject.h>
#include <tcinit/tcinit.h>
#include <time.h>

#define CALLAPI(expr)ITKCALL(ifail = expr); if(ifail != ITK_ok)return ifail;

static int PrintErrorStack( void )
{
	int iNumErrs = 0;
	const int *pSevLst = NULL;
	const int *pErrCdeLst = NULL;
	const char **pMsgLst = NULL;
	register int i = 0;
 
	EMH_ask_errors( &iNumErrs, &pSevLst, &pErrCdeLst, &pMsgLst );
	fprintf( stderr, "Error(s): \n");
	
	for ( i = 0; i < iNumErrs; i++ )
	{
		fprintf( stderr, "\t%6d: %s\n", pErrCdeLst[i], pMsgLst[i] );
	}
	return ITK_ok;
 }
 
  int save_object (tag_t object_tag)
 {
    int ReturnCode;
   /* Save the object. */
    ReturnCode = AOM_save (object_tag);
    if (ReturnCode != ITK_ok)
    {
     //output_error ("ERROR %d save object.\n", ReturnCode);
      return (ReturnCode);
    }
	/* Unlock the object. */
 
	ReturnCode = AOM_unlock (object_tag);
     return (ReturnCode);
 }
 
  int trim(char *str)
 {
	char *ptr = NULL;
	int i,j=0;
	ptr = (char*)malloc((strlen(str)+1) * 2);
	for(i=0;str[i]!='\0';i++)
	{
	if (str[i] != ' ' && str[i] != '\t')
		ptr[j++]=str[i];
	}
	ptr[j]='\0';
	str=ptr;
	free(ptr);
	return 0;
 }
 
 extern int ITK_user_main( int argc, char **argv )
 {
 //Generates a Item ID for a user.
	USER_new_item_id(NULLTAG,type_tag,&mod,&id);

line->item_id = id;

ITEM_create_item( line->item_id,line->item_name,line->item_type,NULL,&item,&rev );
ifail = ITEM_save_item( item);

ifail = ITEM_create_rev( item, NULL, &rev );
ifail = ITEM_save_rev( rev);

ifail = ITEM_ask_name (item, name);
ifail = ITEM_set_name (item, line->item_name);
//Need to save the item otherwise item name can not set
ifail = AOM_save(item);

ifail = ITEM_set_rev_name (rev, line->item_rev_name);
//Need to save the item rev otherwise item rev name can not set
ifail = AOM_save(rev);

//This function will get the type of the Item.type ->char array
ITEM_ask_type (item, type);

//This function will return the tag of a specific Item Revision
//If more than one match (case insensitive) is found, an error is returned
ITEM_find_revision( item, default_null_to_A(line->item_revision_id), &rev );

//This function searches the database for all Item Revisions (of the given Item)
ITEM_find_revisions
	
 }