#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource_;

public:
    // Konstruktor domyślny
    ResourceManager() : resource_(new Resource()) {}

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource_(other.resource_) {}

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource_ = other.resource_;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : resource_(std::move(other.resource_)) {}

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            resource_ = std::move(other.resource_);
        }
        return *this;
    }

    double get() const { return resource_->get(); }

    ~ResourceManager() { delete resource_; }
};
