/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_MODEL_FIELD_TRANSFORM_H_
#define FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_MODEL_FIELD_TRANSFORM_H_

#include <memory>
#include <string>
#include <utility>

#include "Firestore/core/src/firebase/firestore/model/field_path.h"

namespace firebase {
namespace firestore {
namespace model {

class TransformOperation;

/** A field path and the TransformOperation to perform upon it. */
class FieldTransform {
 public:
  FieldTransform(FieldPath path,
                 std::unique_ptr<TransformOperation> transformation) noexcept;

  const FieldPath& path() const {
    return path_;
  }

  const TransformOperation& transformation() const {
    return *transformation_.get();
  }

  bool operator==(const FieldTransform& other) const;

  size_t Hash() const;

  std::string ToString() const;

 private:
  FieldPath path_;
  // Shared by copies of the same FieldTransform.
  std::shared_ptr<const TransformOperation> transformation_;
};

}  // namespace model
}  // namespace firestore
}  // namespace firebase

#endif  // FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_MODEL_FIELD_TRANSFORM_H_
