#include"common.h"
#include"test.h"
int main(int argc, char** argv)
{
#ifdef DEBUG
    test_shudu();
#endif
    bool ret = ui_loop(argc, argv);
    if (!ret) {
        cout << "请输入正确的格式!!!" << endl;
        return 0;
    }
    else {
        return 0;
    }
}