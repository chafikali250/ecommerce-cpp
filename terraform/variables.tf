variable "location" {
  type        = string
  default     = "francecentral"
}

variable "resource_group_name" {
  type        = string
  default     = "rg-ecommerce-cpp-prod"
}

variable "app_service_plan_name" {
  type        = string
  default     = "asp-ecommerce-cpp"
}

variable "app_service_name" {
  type        = string
  default     = "app-ecommerce-cpp-chafik250"
}

variable "docker_image" {
  type        = string
  default     = "chali250/ecommerce-cpp:latest"
}
