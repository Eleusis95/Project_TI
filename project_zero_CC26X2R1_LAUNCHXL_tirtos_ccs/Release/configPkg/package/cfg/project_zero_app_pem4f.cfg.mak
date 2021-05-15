# invoke SourceDir generated makefile for project_zero_app.pem4f
project_zero_app.pem4f: .libraries,project_zero_app.pem4f
.libraries,project_zero_app.pem4f: package/cfg/project_zero_app_pem4f.xdl
	$(MAKE) -f C:\Users\arigd\Desktop\BLE\projecto\project_zero_CC26X2R1_LAUNCHXL_tirtos_ccs/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\arigd\Desktop\BLE\projecto\project_zero_CC26X2R1_LAUNCHXL_tirtos_ccs/src/makefile.libs clean

