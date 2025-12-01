#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "unordered_map.h"

namespace CP {

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT, MappedT, HasherT, EqualT>::next_cost(iterator it) {
    size_t move = 0;
    
    if (it == this->end())
    {
        return 0;
    }

    size_t bucketIndex = this->hash_to_bucket(it->first);
    ValueIterator iteratorInBucket = this->find_in_bucket(mBuckets[bucketIndex], it->first);
    iteratorInBucket++;

    if (iteratorInBucket != mBuckets[bucketIndex].end())
    {
        return 1;
    }

    ++move;

    for (size_t i = bucketIndex + 1; i < this->mBuckets.size(); ++i)
    {
        ++move;
        if (!this->mBuckets[i].empty())
        {
            return move;
        }
    }

    ++move;

    return move;
}
}

#endif


