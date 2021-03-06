#include "meanSquareErrorCost.h"
#include "matrix.h"

NNDataType MeanSquareErrorCost::calculateCost(const NNMatrixType &output, const NNMatrixType &target) const
{
    NNDataType error = 0;
    NNMatrixType difference = output - target;
    for (auto it = difference.cbegin(); it < difference.cend(); ++it)
    {
        error += *it * (*it);
    }
    return 0.5 * error;
}

NNMatrixType MeanSquareErrorCost::calculateCostDerivative(const NNMatrixType &output, const NNMatrixType &target) const
{
    return output - target;
}

void MeanSquareErrorCost::serialize(std::ofstream &ofile) const
{
    const char *id = "MSE";
    const unsigned int ID_SIZE = 3;
    ofile.write((char *)&ID_SIZE, sizeof(ID_SIZE));
    ofile.write(id, ID_SIZE * sizeof(char));
}