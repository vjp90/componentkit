/*
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#import <ComponentKit/CKDefines.h>

#if CK_NOT_SWIFT

@protocol CKComponentProtocol;

class CKActionBase;

namespace CK {
  class BaseRenderContext {

  protected:
    id<CKComponentProtocol> _component;
    
    BaseRenderContext(const BaseRenderContext &) = default;
    BaseRenderContext& operator=(const BaseRenderContext &) = default;

  public:
    BaseRenderContext(const id<CKComponentProtocol> component): _component(component) {}
    BaseRenderContext(): _component(nullptr) {}
    
    BaseRenderContext(BaseRenderContext &&) = default;
    BaseRenderContext& operator=(BaseRenderContext&&) = default;

    template <typename Component>
    friend inline auto component(const BaseRenderContext &context) -> Component;

    friend class ::CKActionBase;
  };
}

#endif
