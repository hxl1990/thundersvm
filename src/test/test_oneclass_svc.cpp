//
// Created by jiashuai on 17-10-9.
//
#include <gtest/gtest.h>
#include <thundersvm/model/oneclass_svc.h>
#include <dataset.h>

TEST(OneClassSVCTest, train) {
    DataSet dataSet;
    dataSet.load_from_file(DATASET_DIR "test_dataset.txt");
    SvmParam param;
    param.gamma = 0.5;
    param.nu = 0.5;
    SvmModel *model = new OneClassSVC(dataSet, param);
    model->train();

    vector<real> predict_y = model->predict(dataSet.instances(), 100);
    int n_pos = 0;
    for (int i = 0; i < predict_y.size(); ++i) {
        if (predict_y[i] > 0)
            n_pos++;
    }
    EXPECT_EQ(n_pos, 76);
}
