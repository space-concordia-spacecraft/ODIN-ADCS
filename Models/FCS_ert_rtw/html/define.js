function CodeDefine() { 
this.def = new Array();
this.def["ert_main.cpp:FCS_Obj"] = {file: "ert_main_cpp.html",line:20,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_cpp.html",line:34,type:"fcn"};
this.def["main"] = {file: "ert_main_cpp.html",line:71,type:"fcn"};
this.def["step"] = {file: "FCS_cpp.html",line:19,type:"fcn"};
this.def["initialize"] = {file: "FCS_cpp.html",line:25,type:"fcn"};
this.def["terminate"] = {file: "FCS_cpp.html",line:34,type:"fcn"};
this.def["getRTM"] = {file: "FCS_cpp.html",line:55,type:"fcn"};
this.def["ConstB_FCS_T"] = {file: "FCS_h.html",line:48,type:"type"};
this.def["ExtU_FCS_T"] = {file: "FCS_h.html",line:54,type:"type"};
this.def["ExtY_FCS_T"] = {file: "FCS_h.html",line:61,type:"type"};
this.def["errorStatus"] = {file: "FCS_h.html",line:65,type:"var"};
this.def["FCS_ConstB"] = {file: "FCS_data_cpp.html",line:19,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:47,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:95,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:102,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:109,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:116,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:123,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:130,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:148,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_cpp.html"] = "../ert_main.cpp";
	this.html2Root["ert_main_cpp.html"] = "ert_main_cpp.html";
	this.html2SrcPath["FCS_cpp.html"] = "../FCS.cpp";
	this.html2Root["FCS_cpp.html"] = "FCS_cpp.html";
	this.html2SrcPath["FCS_h.html"] = "../FCS.h";
	this.html2Root["FCS_h.html"] = "FCS_h.html";
	this.html2SrcPath["FCS_private_h.html"] = "../FCS_private.h";
	this.html2Root["FCS_private_h.html"] = "FCS_private_h.html";
	this.html2SrcPath["FCS_types_h.html"] = "../FCS_types.h";
	this.html2Root["FCS_types_h.html"] = "FCS_types_h.html";
	this.html2SrcPath["FCS_data_cpp.html"] = "../FCS_data.cpp";
	this.html2Root["FCS_data_cpp.html"] = "FCS_data_cpp.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_cpp.html","FCS_cpp.html","FCS_h.html","FCS_private_h.html","FCS_types_h.html","FCS_data_cpp.html","rtwtypes_h.html"];
