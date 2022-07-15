#include "CT4_ClassificationObj.hxx"


 string ChangeMatrix::computeTransformationMatrix(string &transformationMatrix,
									double &x, double &y, double &z,
									double &alpha, double &beta, double &gamma) {
	
	//double unitMatrix[4][4] = { { 1.0, 0.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0, 0.0 },
	//		{ 0.0, 0.0, 1.0, 0.0 }, { 0.0, 0.0, 0.0, 1.0 } };



	 TC_write_syslog("\n computeTransformationMatrix transformationMatrix -------->%s", transformationMatrix.c_str());

	 string matrixEntries[OCCMatrixMAXVAL];
	 char Exisitngmatrix[240];


	 int index = 0;
	 if (transformationMatrix.size() > 0)
	 {
		 char* next_token1 = NULL;
		 strcpy_s(Exisitngmatrix, transformationMatrix.c_str());
		 char* pch = strtok_s(Exisitngmatrix, " ", &next_token1);

		 while (pch != NULL)
		 {
			 if (strlen(pch) > 0)
			 {
				 matrixEntries[index].assign(pch);
				 index++;
			 }
			 pch = strtok_s(NULL, " ", &next_token1);
		 }
	 }

	for (int ii = 0; ii < index ; ii ++)
		TC_write_syslog("\n  matrixEntries[%d] = %s", ii, matrixEntries[ii]);


	 double matrix[4][4];
	 int column = 0;
	 for (int i = 0; i < index; i++) {
		 column = i / 4;
		 matrix[column][i % 4] = atof(matrixEntries[i].c_str());
	 }


	 for (int ii = 0; ii < 4; ii++)
		 for (int jj = 0; jj < 4; jj++)
		 TC_write_syslog("\n  matrix[%d][%d] = %f", ii,jj, matrix[ii][jj]);


	 string stringRelativeTransformationMatrix = "";


	

	std::vector < std::vector <double>> relativeTransformationMatrix =translate(matrix, x, y, z);

	for (int ii = 0; ii < 4; ii++)
		for (int jj = 0; jj < 4; jj++)
			TC_write_syslog("\n  after translate relativeTransformationMatrix[%d][%d] = %f", ii, jj, relativeTransformationMatrix[ii][jj]);

	for (int ii = 0; ii < 4; ii++)
		for (int jj = 0; jj < 4; jj++)
			TC_write_syslog("\n  after translate relativeTransformationMatrix[%d][%d] = %f", ii, jj, relativeTransformationMatrix[ii][jj]);


	relativeTransformationMatrix = rotate(relativeTransformationMatrix, alpha, beta, gamma);


	for (int ii = 0; ii < 4; ii++)
		for (int jj = 0; jj < 4; jj++)
			TC_write_syslog("\n  after rotate === relativeTransformationMatrix[%d][%d] = %f", ii, jj, relativeTransformationMatrix[ii][jj]);

	TC_write_syslog("\n");
	for (int ii = 0; ii < 4; ii++)
	{
		for (int jj = 0; jj < 4; jj++)
			TC_write_syslog("%f \t \t", relativeTransformationMatrix[ii][jj]);
		TC_write_syslog("\n");
	}



	 relativeTransformationMatrix = imageSwap(relativeTransformationMatrix);


	 for (int ii = 0; ii < 4; ii++)
		 for (int jj = 0; jj < 4; jj++)
			 TC_write_syslog("\n  imageSwap === relativeTransformationMatrix[%d][%d] = %f", ii, jj, relativeTransformationMatrix[ii][jj]);


	 TC_write_syslog("\n");
	 for (int ii = 0; ii < 4; ii++)
	 {
		 for (int jj = 0; jj < 4; jj++)
			 TC_write_syslog("%f \t \t", relativeTransformationMatrix[ii][jj]);
		 TC_write_syslog("\n");
	 }


	for ( vector<double> element : relativeTransformationMatrix) {
			for ( double number : element) {
				char buf[20];
				sprintf_s(buf, "%f", number);
				stringRelativeTransformationMatrix.append(buf);
				stringRelativeTransformationMatrix.append(" ");
			}
		}

	TC_write_syslog("\n  stringRelativeTransformationMatrix = %s", stringRelativeTransformationMatrix.c_str());

	return stringRelativeTransformationMatrix;
}

 std::vector<std::vector<double>> ChangeMatrix::translate(double matrix[4][4], double x, double y, double z) {
	 std::vector < std::vector <double>> translationMatrix;

	 TC_write_syslog("\n x, y z -------->%f  %f %f\n", x,y,z);

	 for (int i = 0; i < 4; i++)
		 for (int j = 0; j < 4; j++)
			 TC_write_syslog("\n matrix[%d][%d]=%f",i,j,matrix[i][j]);


	 for (int i = 0; i < 4; i++)
	 {
		 vector<double> v1;

		 for (int j = 0; j < 4; j++)
		 {
			 //translationMatrix[i][j] = matrix[i][j];
			 v1.push_back(matrix[i][j]);

		 }
		 translationMatrix.push_back(v1);
	 }


	 //mm to mt
	 translationMatrix[0][3] = round((x / 1000)*100)/100;
	 translationMatrix[1][3] = round((y / 1000) * 100) / 100;
	 translationMatrix[2][3] = round((z / 1000) * 100) / 100;

	 return translationMatrix;
 }

 /**
  * Compute the rotation values from the transformation matrix.
  */
 void ChangeMatrix::getRotationValues(string transformationMatrix) {
		
	 string matrixEntries[OCCMatrixMAXVAL];
	 char Exisitngmatrix[240];
	 

	 int index = 0;
	 if (transformationMatrix.size() > 0)
	 {
		 char* next_token1=NULL;
		 strcpy_s(Exisitngmatrix, transformationMatrix.c_str());
		 char* pch = strtok_s(Exisitngmatrix, " ",&next_token1);

		 while (pch != NULL)
		 {
			 if (strlen(pch) > 0)
			 {
				matrixEntries[index].assign(pch);
				 index++;
			 }
			 pch = strtok_s(NULL, " ",&next_token1);
		 }

	 }

		 

		  double matrix[4][4];


		 int column = 0;
		 for (int i = 0; i < index; i++) {
			 column = i / 4;
			 matrix[column][i % 4] = atof(matrixEntries[i].c_str());
		 }

		 if (matrix[2][0] != 1 && matrix[0][2] != -1) {
			 beta = -1 * asin(matrix[0][2]);
			 gamma = atan2(matrix[1][2] / cos(beta), matrix[2][2] / cos(beta));
			 alpha = atan2(matrix[0][1] / cos(beta), matrix[0][0] / cos(beta));
		 }
		 else {
			 alpha = 0;
			 if (matrix[2][1] == -1) {
				 beta = PI / 2;
				 gamma = alpha + atan2(matrix[0][1], matrix[0][2]);
			 }
			 else {
				 beta = -PI / 2;
				 gamma = -1 * beta + atan2(-1 * matrix[0][1], -1 * matrix[0][2]);
			 }
		 }

		 alpha = abs(getPositive((alpha * 180) / PI, 360));
		 beta = abs(getPositive((beta * 180) / PI, 360));
		 gamma = abs(getPositive((gamma * 180) / PI, 360));

		 x = 1000 * matrix[3][0];
		 y = 1000 * matrix[3][1];
		 z = 1000 * matrix[3][2];

 }

	 double ChangeMatrix::getPositive(double number, double modulo)
	 {
		 while (number < 0)
		 {
			 number += modulo;
		 }

		 return number;
	 }

	 
	 std::wstring ChangeMatrix::getOldMatrix()
	 {
		 return oldMatrix;
	 }

	 std::vector < std::vector <double>> ChangeMatrix::rotate(std::vector < std::vector <double>> matrix, double alpha, double beta, double gamma)
	 {
		 
		  double cosAlpha = cos(degToRad(alpha));
		  double cosBeta = cos(degToRad(beta));
		  double cosGamma = cos(degToRad(gamma));
		  double sinAlpha = sin(degToRad(alpha));
		  double sinBeta = sin(degToRad(beta));
		  double sinGamma = sin(degToRad(gamma));

		 
		  double firstRow[] = { round((cosAlpha * cosBeta)*100)/100,
				 round(((cosAlpha * sinBeta * sinGamma) - (sinAlpha * cosGamma))*100)/100,
				 round(((cosAlpha * sinBeta * cosGamma) + (sinAlpha * sinGamma))*100)/100, matrix[0][3] };
		  double secondRow[] = { round((sinAlpha * cosBeta)*100)/100,
				 round(((sinAlpha * sinBeta * sinGamma) + (cosAlpha * cosGamma))*100)/100,
				 round(((sinAlpha * sinBeta * cosGamma) - (cosAlpha * sinGamma))*100)/100, matrix[1][3] };
		  double thirdRow[] = { round(-sinBeta*100)/100, round((cosBeta * sinGamma)*100)/100, round((cosBeta * cosGamma)*100)/100,
				 matrix[2][3] };

		  //double rotationMatrix[4][4] = { firstRow, secondRow, thirdRow, matrix[3] };
		  std::vector < std::vector <double>> rotationMatrix;
		  vector<double> firt_row, second_Row, third_Row, matx_Row;
		  firt_row.push_back(firstRow[0]);
		  firt_row.push_back(firstRow[1]);
		  firt_row.push_back(firstRow[2]);
		  firt_row.push_back(firstRow[3]);

		  rotationMatrix.push_back(firt_row);
		 
		  second_Row.push_back(secondRow[0]);
		  second_Row.push_back(secondRow[1]);
		  second_Row.push_back(secondRow[2]);
		  second_Row.push_back(secondRow[3]);

		  rotationMatrix.push_back(second_Row);
		
		  third_Row.push_back(thirdRow[0]);
		  third_Row.push_back(thirdRow[1]);
		  third_Row.push_back(thirdRow[2]);
		  third_Row.push_back(thirdRow[3]);

		  rotationMatrix.push_back(third_Row);

		  matx_Row.push_back(matrix[3][0]);
		  matx_Row.push_back(matrix[3][1]);
		  matx_Row.push_back(matrix[3][2]);
		  matx_Row.push_back(matrix[3][3]);

		  rotationMatrix.push_back(matx_Row);


		 return rotationMatrix;
	 }

	ChangeMatrix::ChangeMatrix()
	 {

		
	 }
	


	 std::vector < std::vector <double>> ChangeMatrix::imageSwap(std::vector < std::vector <double>> matrix ) {
	


		 double mainmatrix[4][4];

		 mainmatrix[0][0] = matrix[0][0];
		mainmatrix[0][1] = matrix[1][0];
		mainmatrix[0][2] = matrix[2][0];
		mainmatrix[0][3] = matrix[3][0];
		mainmatrix[1][0] = matrix[0][1];
		mainmatrix[1][1] = matrix[1][1];
		mainmatrix[1][2] = matrix[2][1];
		mainmatrix[1][3] = matrix[3][1];
		mainmatrix[2][0] = matrix[0][2];
		mainmatrix[2][1] = matrix[1][2];
		mainmatrix[2][2] = matrix[2][2];
		mainmatrix[2][3] = matrix[3][2];
		mainmatrix[3][0] = matrix[0][3];
		mainmatrix[3][1] = matrix[1][3];
		mainmatrix[3][2] = matrix[2][3];
		mainmatrix[3][3] = matrix[3][3];


		matrix[0][0] = mainmatrix[0][0];
		matrix[0][1] = mainmatrix[0][1];
		matrix[0][2] = mainmatrix[0][2];
		matrix[0][3] = mainmatrix[0][3];
		matrix[1][0] = mainmatrix[1][0];
		matrix[1][1] = mainmatrix[1][1];
		matrix[1][2] = mainmatrix[1][2];
		matrix[1][3] = mainmatrix[1][3];
		matrix[2][0] = mainmatrix[2][0];
		matrix[2][1] = mainmatrix[2][1];
		matrix[2][2] = mainmatrix[2][2];
		matrix[2][3] = mainmatrix[2][3];
		matrix[3][0] = mainmatrix[3][0];
		matrix[3][1] = mainmatrix[3][1];
		matrix[3][2] = mainmatrix[3][2];
		matrix[3][3] = mainmatrix[3][3];


		 return matrix;
	 }



