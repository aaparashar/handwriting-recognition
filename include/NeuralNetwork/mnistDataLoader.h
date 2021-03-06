#pragma once

#include "mnistData.h"

class MNISTDataLoader
{
typedef std::vector<std::shared_ptr<NNMatrixType>> MatrixVec;
public:
    static MNISTData* loadData(const char* trainingImagesFilename,
                               const char* trainingLabelsFilename,
                               const char* testingImagesFilename,
                               const char* testingLabelsFilename);
private:
    static int reverseInt(int number);

    static void loadImages(const char* imagesFilename, std::vector<char*> &images, int &nLoadedImages, int &imagePixels);
    static char* loadLabels(const char* labelsFilename, int &nLoadedLabels);

    static void createMatriciesFromRawData(const std::vector<char*> &images, const char* labels, int nData, int imagePixels, MatrixVec& imagesMatricies, MatrixVec& lablesMatricies);

    MNISTDataLoader();
};