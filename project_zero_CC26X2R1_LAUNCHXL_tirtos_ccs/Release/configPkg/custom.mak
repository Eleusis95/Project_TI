## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,em4f linker.cmd package/cfg/project_zero_app_pem4f.oem4f

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/project_zero_app_pem4f.xdl
	$(SED) 's"^\"\(package/cfg/project_zero_app_pem4fcfg.cmd\)\"$""\"C:/Users/arigd/Desktop/BLE/projecto/project_zero_CC26X2R1_LAUNCHXL_tirtos_ccs/Release/configPkg/\1\""' package/cfg/project_zero_app_pem4f.xdl > $@
	-$(SETDATE) -r:max package/cfg/project_zero_app_pem4f.h compiler.opt compiler.opt.defs
