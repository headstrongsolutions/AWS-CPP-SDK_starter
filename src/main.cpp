#include <iostream>
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/Bucket.h>
#include <awsdoc/s3/s3_examples.h>

bool AwsDoc::S3::ListBuckets()
{
    Aws::S3::S3Client s3_client;
    Aws::S3::Model::ListBucketsOutcome outcome = s3_client.ListBuckets();

    if (outcome.IsSuccess())
    {
        std::cout << "Bucket names:" << std::endl << std::endl;

        Aws::Vector<Aws::S3::Model::Bucket> buckets =
            outcome.GetResult().GetBuckets();

        for (Aws::S3::Model::Bucket& bucket : buckets)
        {
            std::cout << bucket.GetName() << std::endl;
        }

        return true;
    }
    else
    {
        std::cout << "Error: ListBuckets: "
            << outcome.GetError().GetMessage() << std::endl;

        return false;
    }
}

int main()
{
    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        if (!AwsDoc::S3::ListBuckets())
        {
            return 1;
        }
    }
    Aws::ShutdownAPI(options);

    return 0;
}