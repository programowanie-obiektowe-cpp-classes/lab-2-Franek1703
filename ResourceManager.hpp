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
   ResourceManager(const ResourceManager& other) : resource_(new Resource(*other.resource_)) {}

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            delete resource_;
            resource_ = new Resource(*other.resource_);
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : resource_(other.resource_) {
        other.resource_ = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            delete resource_;
            resource_ = other.resource_;
            other.resource_ = nullptr;
        }
        return *this;
    }

    double get() const
    {
        if (resource_) {
            return resource_->get();
        }
        throw std::runtime_error("Resource is not initialized.");
    }

    ~ResourceManager() {
        delete resource_;
    }
};
