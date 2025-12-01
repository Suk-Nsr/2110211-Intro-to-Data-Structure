#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT,MappedT,HasherT,EqualT>::max_bucket_length() {
    // your code here
    size_t maxBucketLength = this->mBuckets[0].size();
    for (BucketT mBucket : mBuckets)
    {
        if (mBucket.size() > maxBucketLength)
        {
            maxBucketLength = mBucket.size();
        }
    }
    return maxBucketLength;
}

#endif
