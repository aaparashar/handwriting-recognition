#pragma once

#include "costFunctionStrategy.h"

class MeanSquareErrorCost : public CostFunctionStrategy
{
public:
    virtual NNDataType calculateCost(const NNMatrixType &output, const NNMatrixType &target) const;
    virtual NNMatrixType calculateCostDerivative(const NNMatrixType &output, const NNMatrixType &target) const;
    virtual void serialize(std::ofstream &ofile) const;
};