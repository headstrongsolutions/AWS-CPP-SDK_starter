#include <iostream>
#include <aws/core/Aws.h>

int main() {
    std::cout << "Testing main stuff" << std::endl;

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        // make your SDK calls here.
    }
    Aws::ShutdownAPI(options);
    return 0;
}