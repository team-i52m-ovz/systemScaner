#include "../JSONModelsConverter.h"

using namespace SystemRat::JSONModelsConverter;

std::shared_ptr<SystemRat::Models::Win32_BaseboardModel> JSONModelsConverter::createBaseboardModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_BaseboardModel>();
	model->depth() = object["Depth"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->height() = object["Height"].get<std::string>();
	model->hostingBoard() = object["HostingBoard"].get<std::string>() == "true";
	model->installDate() = object["InstallDate"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->model() = object["Model"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->partNUmber() = object["PartNumber"].get<std::string>();
	model->poweredOn() = object["PoweredOn"].get<std::string>() == "true";
	model->product() = object["Product"].get<std::string>();
	model->removable() = object["Removable"].get<std::string>() == "true";
	model->repleacable() = object["Replaceable"].get<std::string>() == "true";
	model->requirementsDescription() = object["RequirementsDescription"].get<std::string>();
	model->requiresDaughterBoard() = object["RequiresDaughterBoard"].get<std::string>() == "true";
	model->serialNumber() = object["SerialNumber"].get<std::string>();
	model->slotLayout() = object["SlotLayout"].get<std::string>();
	model->specialRequirements() = object["SpecialRequirements"].get<std::string>();
	model->status() = object["Status"].get<std::string>();
	model->weight() = object["Weight"].get<std::string>();
	model->width() = object["Width"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createBaseboardModel(std::shared_ptr<SystemRat::Models::Win32_BaseboardModel> model)
{
	json str;
	str["Depth"] = model->depth();
	str["Description"] = model->description();
	str["Height"] = model->height();
	str["HostingBoard"] = model->hostingBoard() ? "true" : "false";
	str["InstallDate"] = model->installDate();
	str["Manufacturer"] = model->manufacturer();
	str["Model"] = model->model();
	str["Name"] = model->name();
	str["PartNumber"] = model->partNUmber();
	str["PoweredOn"] = model->poweredOn() ? "true" : "false";
	str["Product"] = model->product();
	str["Removable"] = model->removable() ? "true" : "false";
	str["Replaceable"] = model->repleacable() ? "true" : "false";
	str["RequirementsDescription"] = model->requirementsDescription();
	str["RequiresDaughterBoard"] = model->requiresDaughterBoard() ? "true" : "false";
	str["SerialNumber"] = model->serialNumber();
	str["SpecialRequirements"] = model->specialRequirements();
	str["Status"] = model->status();
	str["Weight"] = model->weight();
	str["Width"] = model->width();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_BIOSModel> JSONModelsConverter::createBIOSModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_BIOSModel>();
	model->buildNUmber() = object["BuildNumber"].get<std::string>();
	model->codeSet() = object["CodeSet"].get<std::string>();
	model->currentLangudge() = object["CurrentLanguage"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->embeddedControllerMajorVersion() = object["EmbeddedControllerMajorVersion"].get<std::string>();
	model->embeddedControllerMinorVersion() = object["EmbeddedControllerMinorVersion"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->primaryBios() = object["PrimaryBIOS"].get<std::string>() == "true";
	model->serialNumber() = object["SerialNumber"].get<std::string>();
	model->softwareElementId() = object["SoftwareElementID"].get<std::string>();
	model->systemBiosMajorVersion() = object["SystemBiosMajorVersion"].get<std::string>();
	model->systemBiosMinorVersion() = object["SystemBiosMinorVersion"].get<std::string>();
	model->targetOperatingSystem() = object["TargetOperatingSystem"].get<std::string>();
	model->version() = object["Version"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createBIOSModel(std::shared_ptr<SystemRat::Models::Win32_BIOSModel> model)
{
	json str;
	str["BuildNumber"] = model->buildNUmber();
	str["CodeSet"] = model->codeSet();
	str["CurrentLanguage"] = model->currentLangudge();
	str["Description"] = model->description();
	str["EmbeddedControllerMajorVersion"] = model->embeddedControllerMajorVersion();
	str["EmbeddedControllerMinorVersion"] = model->embeddedControllerMinorVersion();
	str["InstallDate"] = model->installDate();
	str["Manufacturer"] = model->manufacturer();
	str["Name"] = model->name();
	str["PrimaryBIOS"] = model->primaryBios() ? "true" : "false";
	str["SerialNumber"] = model->serialNumber();
	str["SoftwareElementID"] = model->softwareElementId();
	str["SystemBiosMajorVersion"] = model->systemBiosMajorVersion();
	str["SystemBiosMinorVersion"] = model->systemBiosMinorVersion();
	str["TargetOperatingSystem"] = model->targetOperatingSystem();
	str["Version"] = model->version();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_ComputerSystemModel> JSONModelsConverter::createComputerSystemModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_ComputerSystemModel>();
	model->adminPasswordStatus() = object["AdminPasswordStatus"].get<std::string>();
	model->bootupState() = object["BootupState"].get<std::string>();
	model->caption() = object["Caption"].get<std::string>();
	model->creationClassName() = object["CreationClassName"].get<std::string>();
	model->dnsHostName() = object["DNSHostName"].get<std::string>();
	model->domain()= object["Domain"].get<std::string>();
	model->lastLoadInfo() = object["LastLoadInfo"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->model() = object["Model"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->networkServerModelEnabled() = object["NetworkServerModeEnabled"].get<std::string>() == "true";
	model->numberOfLogicalProcessors() = object["NumberOfLogicalProcessors"].get<std::string>();
	model->numberOfProcessors() = object["NumberOfProcessors"].get<std::string>();
	model->powerManagementSupported() = object["PowerManagementSupported"].get<std::string>() == "true";
	model->primaryOwnerName() = object["PrimaryOwnerName"].get<std::string>();
	model->systemFamily() = object["SystemFamily"].get<std::string>();
	model->username() = object["UserName"].get<std::string>();
	model->wakeUpType() = object["WakeUpType"].get<std::string>();
	model->workgroup() = object["Workgroup"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createComputerSystemModel(std::shared_ptr<SystemRat::Models::Win32_ComputerSystemModel> model)
{
	json str;
	str["AdminPasswordStatus"] = model->adminPasswordStatus();
	str["BootupState"] = model->bootupState();
	str["Caption"] = model->caption();
	str["CreationClassName"] = model->creationClassName();
	str["DNSHostName"] = model->dnsHostName();
	str["Domain"] = model->domain();
	str["LastLoadInfo"] = model->lastLoadInfo();
	str["Manufacturer"] = model->manufacturer();
	str["Model"] = model->model();
	str["Name"] = model->name();
	str["NetworkServerModeEnabled"] = model->networkServerModelEnabled() ? "true" : "false";
	str["NumberOfLogicalProcessors"] = model->numberOfLogicalProcessors();
	str["NumberOfProcessors"] = model->numberOfProcessors();
	str["PowerManagementSupported"] = model->powerManagementSupported() ? "true" : "false";
	str["PrimaryOwnerName"] = model->primaryOwnerName();
	str["SystemFamily"] = model->systemFamily();
	str["UserName"] = model->username();
	str["WakeUpType"] = model->wakeUpType();
	str["Workgroup"] = model->workgroup();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_DesktopMonitorModel> JSONModelsConverter::createDesktopMonitorModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_DesktopMonitorModel>();
	model->availability() = object["Availability"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->deviceId() = object["DeviceID"].get<std::string>();
	model->isLocked() = object["IsLocked"].get<std::string>() == "true";
	model->monitorManufacturer() = object["MonitorManufacturer"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->pixelsPerXLogicalInch() = object["PixelsPerXLogicalInch"].get<std::string>();
	model->pixelsPerYLogicalInch() = object["PixelsPerYLogicalInch"].get<std::string>();
	model->powerManagementSupported() = object["PowerManagementSupported"].get<std::string>() == "true";
	model->screenHeight() = object["ScreenHeight"].get<std::string>();
	model->screenWidth() = object["ScreenWidth"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createDesktopMonitorModel(std::shared_ptr<SystemRat::Models::Win32_DesktopMonitorModel> model)
{
	json str;
	str["Availability"] = model->availability();
	str["Description"] = model->description();
	str["DeviceID"] = model->deviceId();
	str["IsLocked"] = model->isLocked() ? "true" : "false";
	str["MonitrManufacturer"] = model->monitorManufacturer();
	str["Name"] = model->name();
	str["PixelsPerXLogicalInch"] = model->pixelsPerXLogicalInch();
	str["PixelsPerYLogicalInch"] = model->pixelsPerYLogicalInch();
	str["PowerManagementSupported"] = model->powerManagementSupported() ? "true" : "false";
	str["ScreenHeight"] = model->screenHeight();
	str["ScreenWidth"] = model->screenWidth();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_DiskDriveModel> JSONModelsConverter::createDiskDriveModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_DiskDriveModel>();
	model->availability() = object["Availability"].get<std::string>();
	model->bytesPerSector() = object["BytesPerSector"].get<std::string>();
	model->compressionMethod() = object["CompressionMethod"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->deviceId() = object["DeviceID"].get<std::string>();
	model->errorDescription() = object["ErrorDescription"].get<std::string>();
	model->index() = object["Index"].get<std::string>();
	model->lastErrorCode() = object["LastErrorCode"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->maxBlockSize() = object["MaxBlockSize"].get<std::string>();
	model->mediaLoaded() = object["MediaLoaded"].get<std::string>()== "true";
	model->mediaType() = object["MediaType"].get<std::string>();
	model->model() = object["Model"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->needsCleaning() = object["NeedsCleaning"].get<std::string>() == "true";
	model->serialNumber() = object["SerialNumber"].get<std::string>();
	model->signature() = object["Signature"].get<std::string>();
	model->size() = object["Size"].get<std::string>();
	model->totalCylinders() = object["TotalCylinders"].get<std::string>();
	model->totalHeads() = object["TotalHeads"].get<std::string>();
	model->totalSectors() = object["TotalSectors"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createDiskDriveModel(std::shared_ptr<SystemRat::Models::Win32_DiskDriveModel> model)
{
	json str;
	str["Availability"] = model->availability();
	str["BytesPerSector"] = model->bytesPerSector();
	str["CompressionMethod"] = model->compressionMethod();
	str["Description"] = model->description();
	str["ErrorDescription"] = model->description();
	str["Index"] = model->index();
	str["LastErrorCode"] = model->lastErrorCode();
	str["Manufacturer"] = model->manufacturer();
	str["MaxBlockSize"] = model->maxBlockSize();
	str["MediaLoaded"] = model->mediaLoaded() ? "true" : "false";
	str["MediaType"] = model->mediaType();
	str["Model"] = model->model();
	str["Name"] = model->name();
	str["NeedsCleaninng"] = model->needsCleaning() ? "true" : "false";
	str["SerialNumber"] = model->serialNumber();
	str["Size"] = model->size();
	str["TotalCylinders"] = model->totalCylinders();
	str["TotalHeads"] = model->totalHeads();
	str["TotalSectors"] = model->totalSectors();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_KeyboardModel> JSONModelsConverter::createKeyboardModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_KeyboardModel>();
	model->availability()= object["Availability"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->deviceId() = object["DeviceID"].get<std::string>();
	model->errorDecription() = object["ErrorDescription"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->isLocked() = object["IsLocked"].get<std::string>() == "true";
	model->lastErrorCode() = object["LastErrorCode"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->numberOfFunctionKeys() = object["NumberOfFunctionKeys"].get<std::string>();
	model->password() = object["Password"].get<std::string>();
	model->powerManagementSupported() = object["PowerManagementSupported"].get<std::string>() == "true";
	return model;
}

std::string JSONModelsConverter::createKeyboardModel(std::shared_ptr<SystemRat::Models::Win32_KeyboardModel> model)
{
	json str;
	str["Availability"] = model->availability();
	str["Description"] = model->description();
	str["DeviceID"] = model->deviceId();
	str["ErrorDescription"] = model->errorDecription();
	str["InstallDate"] = model->installDate();
	str["IsLocked"] = model->isLocked() ? "true" : "false";
	str["LastErrorCode"] = model->lastErrorCode();
	str["Name"] = model->name();
	str["NumberOfFunctionKeys"] = model->numberOfFunctionKeys();
	str["Password"] = model->password();
	str["PowerManagementSupported"] = model->powerManagementSupported() ? "true" : "false";
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_NetworkClientModel> JSONModelsConverter::createNetworkCLientModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_NetworkClientModel>();
	model->caption() = object["Caption"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->status() = object["Status"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createNetworkCLientModel(std::shared_ptr<SystemRat::Models::Win32_NetworkClientModel> model)
{
	json str;
	str["Caption"] = model->caption();
	str["Description"] = model->description();
	str["InstallDate"] = model->installDate();
	str["Manufacturer"] = model->manufacturer();
	str["Name"] = model->name();
	str["Status"] = model->status();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_OperatingSystemModel> JSONModelsConverter::createOperatingSystemModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_OperatingSystemModel>();
	model->buildType() = object["BuildType"].get<std::string>();
	model->countryCode() = object["CountryCode"].get<std::string>();
	model->currentTimezone() = object["CurrentTimeZone"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->freePhysicalMemory() = object["FreePhysicalMemory"].get<std::string>();
	model->freeSpaceInPagingFiles() = object["FreeSpaceInPagingFiles"].get<std::string>();
	model->freeVirtualMemory() = object["FreeVirtualMemory"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->maxNumberOfProcesses() = object["MaxNumberOfProcesses"].get<std::string>();
	model->maxProcessesMemorySize() = object["MaxProcessMemorySize"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->nuildNumber() = object["BuildNumber"].get<std::string>();
	model->numberOfLicensedUsers() = object["NumberOfLicensedUsers"].get<std::string>();
	model->numberOfProcesses() = object["NumberOfProcesses"].get<std::string>();
	model->numberOfUsers() = object["NumberOfUsers"].get<std::string>();
	model->organization() = object["Organization"].get<std::string>();
	model->serialNumber() = object["SerialNumber"].get<std::string>();
	model->servicePackMajorVersion() = object["ServicePackMajorVersion"].get<std::string>();
	model->servicePackMinorVersion() = object["ServicePackMinorVersion"].get<std::string>();
	model->status() = object["Status"].get<std::string>();
	model->systemDevice() = object["SystemDevice"].get<std::string>();
	model->systemDrive() = object["SystemDrive"].get<std::string>();
	model->totalVirtualMemorySize() = object["TotalVirtualMemorySize"].get<std::string>();
	model->totalVisibleMemorySize() = object["TotalVisibleMemorySize"].get<std::string>();
	model->version() = object["Version"].get<std::string>();
	model->windowsDirectory() = object["WindowsDirectory"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createOperatingSystemModel(std::shared_ptr<SystemRat::Models::Win32_OperatingSystemModel> model)
{
	json str;
	str["BuildType"] = model->buildType();
	str["CountryCode"] = model->countryCode();
	str["CurrentTizeZone"] = model->currentTimezone();
	str["Description"] = model->description();
	str["FreePhysicalMemory"] = model->freePhysicalMemory();
	str["FreeSpaceInPagingFiles"] = model->freeSpaceInPagingFiles();
	str["FreeVirtualMemory"] = model->freeVirtualMemory();
	str["InstallDate"] = model->installDate();
	str["Manufacturer"] = model->manufacturer();
	str["MaxNumberOfProcesses"] = model->maxNumberOfProcesses();
	str["MaxProcessemorySize"] = model->maxProcessesMemorySize();
	str["Name"] = model->name();
	str["BuildNumber"] = model->nuildNumber();
	str["NumberOfLicensedUsers"] = model->numberOfLicensedUsers();
	str["NumberOfProcesses"] = model->numberOfProcesses();
	str["NumberOfUsers"] = model->numberOfUsers();
	str["Organization"] = model->organization();
	str["SerialNumber"] = model->serialNumber();
	str["ServicePackMajorVersion"] = model->servicePackMajorVersion();
	str["ServicePackMinorVersion"] = model->servicePackMinorVersion();
	str["Status"] = model->status();
	str["SystemDevice"] = model->systemDevice();
	str["SystemDrive"] = model->systemDrive();
	str["TotalVirtualMemorySize"] = model->totalVirtualMemorySize();
	str["TotalVisibleMemorySize"] = model->totalVisibleMemorySize();
	str["Version"] = model->version();
	str["WindowsDirectory"] = model->windowsDirectory();
	return str.dump();

}

std::shared_ptr<SystemRat::Models::Win32_PointingDeviceModel> JSONModelsConverter::createPointingDeviceModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_PointingDeviceModel>();
	model->availability() = object["Availability"].get<std::string>();
 	model->configManagerErrorCode() = object["ConfigManagerErrorCode"].get<std::string>();
	model->deviceId()= object["DeviceID"].get<std::string>();
	model->errorDescription() = object["ErrorDescription"].get<std::string>();
	model->handedness() = object["Handedness"].get<std::string>();
	model->hardwareType() = object["HardwareType"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->isLocked() = object["IsLocked"].get<std::string>() == "true";
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->numberOfButtons() = object["NumberOfButtons"].get<std::string>();
	model->powerManagementSupported() = object["PowerManagementSupported"].get<std::string>() == "true";
	model->resolution() = object["Resolution"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createPointingDeviceModel(std::shared_ptr<SystemRat::Models::Win32_PointingDeviceModel>model)
{
	json str;
	str["Availability"] = model->availability();
	str["ConfigManagerErrorCode"] = model->configManagerErrorCode();
	str["DeviceID"] = model->deviceId();
	str["ErrorDescription"] = model->errorDescription();
	str["Handedness"] = model->handedness();
	str["HardwareType"] = model->hardwareType();
	str["InstallDate"] = model->installDate();
	str["IsLocked"] = model->isLocked() ? "true" : "false";
	str["Manufacturer"] = model->manufacturer();
	str["Name"] = model->name();
	str["NumberOfButtons"] = model->numberOfButtons();
	str["PowerManagementSupported"] = model->powerManagementSupported() ? "true" : "false";
	str["Resolution"] = model->resolution();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_ProcessorModel> JSONModelsConverter::createProcessorModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_ProcessorModel>();
	model->addressWidth() = object["AddressWidth"].get<std::string>();
	model->architecture() = object["Architecture"].get<std::string>();
	model->cpuStatus() = object["CpuStatus"].get<std::string>();
	model->currentVoltage() = object["CurrentVoltage"].get<std::string>();
	model->errorDescription() = object["ErrorDescription"].get<std::string>();
	model->family() = object["Family"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->loadPercentage() = object["LoadPercentage"].get<std::string>();
	model->level()= object["Level"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->maxClockSpeed() = object["MaxClockSpeed"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->numberOfCores() = object["NumberOfCores"].get<std::string>();
	model->numberOfEnabledCore() = object["NumberOfEnabledCore"].get<std::string>();
	model->numberOfLogicalProcessors() = object["NumberOfLogicalProcessors"].get<std::string>();
	model->partNumber() = object["PartNumber"].get<std::string>();
	model->powerManagementSupported()= object["PowerManagementSupported"].get<std::string>() == "true";
	model->processorId() = object["ProcessorId"].get<std::string>();
	model->processorType() = object["ProcessorType"].get<std::string>();
	model->serialNumber() = object["SerialNumber"].get<std::string>();
	model->socketDesignation() = object["SocketDesignation"].get<std::string>();
	model->threadCount() = object["ThreadCount"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createProcessorModel(std::shared_ptr<SystemRat::Models::Win32_ProcessorModel>model )
{
	json str;
	str["AddressWidth"] = model->addressWidth();
	str["Architecture"] = model->architecture();
	str["CpuStatus"] = model->cpuStatus();
	str["CurrentVoltage"] = model->currentVoltage();
	str["ErrorDescription"] = model->errorDescription();
	str["Family"] = model->family();
	str["InstallDate"] = model->installDate();
	str["LoadPercentage"] = model->loadPercentage();
	str["Level"] = model->level();
	str["Manufacturer"] = model->manufacturer();
	str["MaxClockSpeed"] = model->maxClockSpeed();
	str["Name"] = model->name();
	str["NumberOfCores"] = model->numberOfCores();
	str["NumberOfEnabledCore"] = model->numberOfEnabledCore();
	str["NumberOfLogicalProcessors"] = model->numberOfLogicalProcessors();
	str["PartNumber"] = model->partNumber();
	str["PowerManagementSupported"] = model->powerManagementSupported() ? "true" : "false";
	str["ProcessorId"] = model->processorId();
	str["ProcessorType"] = model->processorType();
	str["SerialNumber"] = model->serialNumber();
	str["SocketDesignation"] = model->socketDesignation();
	str["ThreadCount"] = model->threadCount();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_RegistryModel> JSONModelsConverter::createRegistryModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_RegistryModel>();
	model->currentSize() = object["CurrentSize"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->maximumSize() = object["MaximumSize"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->status() = object["Status"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createRegistryModel(std::shared_ptr<SystemRat::Models::Win32_RegistryModel> model)
{
	json str;
	str["CurrentSize"] = model->currentSize();
	str["Description"] = model->description();
	str["InstallDate"] = model->installDate();
	str["MaximumSize"] = model->maximumSize();
	str["Name"] = model->name();
	str["Status"] = model->status();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_SoundDeviceModel> JSONModelsConverter::createSundDeviceModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_SoundDeviceModel>();
	model->availibility() = object["Availability"].get<std::string>();
	model->deviceId() = object["DeviceID"].get<std::string>();
	model->dmaBufferSIze() = object["DMABufferSize"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->mpu401Address() = object["MPU401Address"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->powerManagementSupported() = object["PowerManagementSupported"].get<std::string>() == "true";
	model->productName() = object["ProductName"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createSundDeviceModel(std::shared_ptr<SystemRat::Models::Win32_SoundDeviceModel>model)
{
	json str;
	str["Availability"] = model->availibility();
	str["DeviceID"] = model->deviceId();
	str["DMABufferSize"] = model->dmaBufferSIze();
	str["InstallDate"] = model->installDate();
	str["Manufacturer"] = model->manufacturer();
	str["MPU401Address"] = model->mpu401Address();
	str["Name"] = model->name();
	str["PowerManagementSupported"] = model->powerManagementSupported() ? "true" : "false;";
	str["ProductName"] = model->productName();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_USBControllerModel> JSONModelsConverter::createUSBControllerModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_USBControllerModel>();
	model->description() = object["Description"].get<std::string>();
	model->deviceId() = object["DeviceID"].get<std::string>();
	model->errorDescription()= object["ErrorDescription"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->manufacturer() = object["Manufacturer"].get<std::string>();
	model->maxNumberControlled() = object["MaxNumberControlled"].get<std::string>();
	model->name() = object["Name"].get<std::string>();
	model->powerManagementSupported() = object["PowerManagementSupported"].get<std::string>() == "true";
	model->protocolSupported()= object["ProtocolSupported"].get<std::string>();
	model->status() = object["Status"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createUSBControllerModel(std::shared_ptr<SystemRat::Models::Win32_USBControllerModel> model)
{
	json str;
	str["Description"] = model->description();
	str["DeviceID"] = model->deviceId();
	str["ErrorDescription"] = model->errorDescription();
	str["InstallDate"] = model->installDate();
	str["Manufacturer"] = model->manufacturer();
	str["MaxNumberControlled"] = model->maxNumberControlled();
	str["Name"] = model->name();
	str["PowerManagementSupported"] = model->powerManagementSupported() ? "true" : "false";
	str["ProtocolSupported"] = model->protocolSupported();
	str["Status"] = model->status();
	return str.dump();
}

std::shared_ptr<SystemRat::Models::Win32_UserAccountModel> JSONModelsConverter::createUserAccountModel(json object)
{
	auto model = std::make_shared<SystemRat::Models::Win32_UserAccountModel>();
	model->accountType() = object["AccountType"].get<std::string>();
	model->description() = object["Description"].get<std::string>();
	model->fullName() = object["FullName"].get<std::string>();
	model->installDate() = object["InstallDate"].get<std::string>();
	model->localAccount() = object["LocalAccount"].get<std::string>() == "true";
	model->lockout() = object["Lockout"].get<std::string>() == "true";
	model->name() = object["Name"].get<std::string>();
	model->passwordChangeable() = object["PasswordChangeable"].get<std::string>() == "true";
	model->passwordExpires() = object["PasswordExpires"].get<std::string>() == "true";
	model->passwordRequired() = object["PasswordRequired"].get<std::string>() == "true";
	model->SID() = object["SID"].get<std::string>();
	model->status() = object["Status"].get<std::string>();
	return model;
}

std::string JSONModelsConverter::createUserAccountModel(std::shared_ptr<SystemRat::Models::Win32_UserAccountModel> model)
{
	json str;
	str["AccountType"] = model->accountType();
	str["Description"] = model->description();
	str["FullName"] = model->fullName();
	str["InstallDate"] = model->installDate();
	str["LocalAccount"] = model->localAccount() ? "true" : "false";
	str["Lockout"] = model->lockout() ? "true" : "false";
	str["Name"] = model->name();
	str["PasswordExpires"] = model->passwordExpires() ? "true" : "false";
	str["PasswordChangeable"] = model->passwordChangeable() ? "true" : "false";
	str["PasswordRequired"] = model->passwordRequired() ? "true" : "false";
	str["SID"] = model->SID();
	str["Status"] = model->status();
	return str.dump();
}