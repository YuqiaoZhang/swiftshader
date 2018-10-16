// Copyright 2018 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef VK_PHYSICAL_DEVICE_HPP_
#define VK_PHYSICAL_DEVICE_HPP_

#include "VkObject.hpp"

namespace vk
{

class PhysicalDevice
{
public:
	static constexpr VkSystemAllocationScope GetAllocationScope() { return VK_SYSTEM_ALLOCATION_SCOPE_DEVICE; }

	PhysicalDevice(const void*, void* mem);
	void destroy(const VkAllocationCallbacks* pAllocator) {}

	static size_t ComputeRequiredAllocationSize(const void*) { return 0; }

	const VkPhysicalDeviceFeatures& getFeatures() const;
	bool hasFeatures(const VkPhysicalDeviceFeatures& requestedFeatures) const;
	const VkPhysicalDeviceProperties& getProperties() const;
	void getFormatProperties(VkFormat format, VkFormatProperties* pFormatProperties) const;
	void getImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling,
	                              VkImageUsageFlags usage, VkImageCreateFlags flags,
	                              VkImageFormatProperties* pImageFormatProperties) const;
	uint32_t getQueueFamilyPropertyCount() const;
	void getQueueFamilyProperties(uint32_t pQueueFamilyPropertyCount,
	                              VkQueueFamilyProperties* pQueueFamilyProperties) const;
	const VkPhysicalDeviceMemoryProperties& getMemoryProperties() const;

private:
	const VkPhysicalDeviceLimits& getLimits() const;
	VkSampleCountFlags getSampleCounts() const;
};

using DispatchablePhysicalDevice = DispatchableObject<PhysicalDevice, VkPhysicalDevice>;

static inline PhysicalDevice* Cast(VkPhysicalDevice object)
{
	return DispatchablePhysicalDevice::Cast(object);
}

} // namespace vk

#endif // VK_PHYSICAL_DEVICE_HPP_