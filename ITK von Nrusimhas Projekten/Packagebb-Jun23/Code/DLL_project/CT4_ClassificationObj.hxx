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
 *   This file contains the declaration for the Extension CT4_ClassificationforModul
 *
 */
 
#//ifndef CT4_CLASSIFICATIONFORMODUL_HXX
//#define CT4_CLASSIFICATIONFORMODUL_HXX
#include <tccore/method.h>
#include "ics\ics.h"
#include "ics\ics2.h"
#include "tccore\aom.h"
#include "tccore\aom_prop.h"
#include "string"
#include "tccore\grm.h"
#include "tccore\item.h"
#include "tc\preferences.h"
#include <vector>
#include "pom\enq\enq.h"
#include <qry\qry.h>
#include <map>
#include "bom\bom.h"
#include "cfm\cfm.h"
#include "tccore\workspaceobject.h"
#include "fclasses\tc_string.h"
#include "sa\tcfile.h"
#include "tc\emh.h"
#include "tccore\tctype.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <optional>
#include <ps/vrule.h>
#include <sa/sa.h>
#include <tccore/workspaceobject.h>
#include <tc/tc.h>


#define OCCMatrixMAXVAL 16
#define degToRad(angleInDegrees) ((angleInDegrees) * PI / 180.0)
#define MAXVAL 6


#define ITK_CALL(x) {           \
    int stat;                     \
    char *err_string;             \
    if( (stat = (x)) != ITK_ok)   \
    {                             \
		EPM_get_error_string (NULLTAG, stat, &err_string);                 \
		TC_write_syslog ("ERROR: %d ERROR MSG: %s.\n", stat, err_string);           \
		TC_write_syslog ("FUNCTION: %s\nFILE: %s LINE: %d\n",#x, __FILE__, __LINE__); \
		if(err_string) MEM_free(err_string);                                \
		//exit (EXIT_FAILURE);                                                   \
    }                                                                    \
}
using namespace std;

//#include <CT4Customlib/libct4customlib_exports.h>
#ifdef __cplusplus
         extern "C"{
#endif
          
			 const std::string WHITESPACE = " \n\r\t\f\v";
extern __declspec(dllexport) int CT4_ClassificationforModul(METHOD_message_t* msg, va_list args);
extern __declspec(dllexport)  int CT4ClassificationObjDel_PostAct(METHOD_message_t* msg, va_list args);
extern __declspec(dllexport) int CT4ClassificationObjDel_PreCond(METHOD_message_t* msg, va_list args);

int UpdatepropwithClasification(tag_t itemrev, tag_t classification, char* class_name, string exttype);
int getSmlb0FromCid(const char* cid, tag_t& tSmlbo);
extern __declspec(dllexport) int CT4populateValuesonIR(METHOD_message_t* msg, va_list args);



extern __declspec(dllexport) int CT4ExtractBOMDataOnSolVar_Save(METHOD_message_t* msg, va_list args);
extern __declspec(dllexport) int CT4ExtractBOMDataOnSolVar_Create(METHOD_message_t* msg, va_list args);
static void printrecursivebom(tag_t line, tag_t Parent, int depth, char* req_item, char* sVariantRule);
string getUpdatedmatrixval(char* PosCorVal, char* MatrixVal, char** pdatedMatrixval);
extern __declspec(dllexport) int CT4_PopulateMassAttr_toMassUOM(METHOD_message_t* msg, va_list args);
int SetMassvalue(char* propval, tag_t itemrev);
string getPosCorbasedVarAttr(char* PosCorVal, char* VarRuleVal);
std::string trim(const std::string& s);
extern  __declspec(dllexport) int CT4_IRDeepCopymethod(METHOD_message_t* msg, va_list args);
extern __declspec(dllexport) int CT4ExtractBOMDataOnCC_Create(METHOD_message_t* msg, va_list args);
void tokenize(std::string const& str, const char delim, std::vector<std::string>& out);
std::string ReplaceString(std::string subject, const std::string& search,
	const std::string& replace);

class ChangeMatrix
{
private:
	std::wstring oldMatrix = L"1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1";


	double alpha = 0;
	double beta = 0;
	double gamma = 0;

	double x = 0;
	double y = 0;
	double z = 0;

public:

	 ChangeMatrix();
	 string computeTransformationMatrix(string& transformationMatrix,
		 double& x, double& y, double& z,
		 double& alpha, double& beta, double& gamma);
	void getRotationValues(string transformationMatrix);
	std::vector < std::vector <double>> rotate(std::vector < std::vector <double>> matrix, double alpha, double beta, double gamma);
	std::vector < std::vector <double>>  imageSwap(std::vector < std::vector <double>> matrix);
	std::vector<std::vector<double>> translate(double matrix[4][4], double x, double y, double z);
	std::wstring getOldMatrix();
	double getPositive(double number, double modulo);
};

#ifdef __cplusplus
                   }
#endif
                
//#include <CT4Customlib/libct4customlib_undef.h>
                
//#endif  // CT4_CLASSIFICATIONFORMODUL_HXX
