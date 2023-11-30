#
# Copyright (C) 2024 Wind River Systems, Inc.
#
# Utilities for processing items depending on the Rolling Cumulative Patch Layer (RCPL)
# version being used.
#
# python function ifRcplInRange(d, first, last, tval, fval) returns tval
# if the RCPL is in a particular range, and fval if it is not.
#
# `first` must be specified.  When `last` is provided, this function returns
# `tval` if the RCPL number is in range [first, last] (inclusive for both lower bound
# and upper bound) and `fval` if the RCPL number is outside the range.
#
# When `last` is not provided, this function returns `tval` if the RCPL number
# is >= `first` and `fval` if the RCPL number is < `first`.
#
# An anonymous python function processes values for SRC_URI_APPEND_RCPL[] flags and
# appends them to SRC_URI if the RCPL is in range.
#
#
# Example usages:
#
# inherit rcpl-filter
#
# SRC_URI = "... \
#            ${@ifRcplInRange(d,tval='file://CVE-2022-37434.patch',first=15)} \
#            ${@ifRcplInRange(d,13,13,'file://CVE-2023-45853.patch')} \
#           "
#
# Include the CVE-2022-37434 patch starting at RCPL0015 (including RCPL0015).
# Include the CVE-2023-45853 patch only for RCPL0013.  Note that the following
# two lines are equivalent.
#
#            ${@ifRcplInRange(d,15,tval='file://CVE-2022-37434.patch')}
#            ${@ifRcplInRange(d,1,14,fval='file://CVE-2022-37434.patch')}
#
# Another way to do this is by using variable flags.
#
# RCPL 15 and above
# SRC_URI_APPEND_RCPL[15-] = "file://CVE-2022-37434.patch"
# only RCPL 13
# SRC_URI_APPEND_RCPL[13] = "file://CVE-2023-45853.patch"
# RCPLs 13-18
# SRC_URI_APPEND_RCPL[13-18] = "file://CVE-2023-45853.patch"
#
# The inline function is more general, and can be used to set values
# anywhere based on an RCPL range.
#

# ifRcplInRange(d,first,last,tval,fval)
#   first    the lowest number RCPL in the range (inclusive)
#   last     the highest number RCPL in the range (inclusive)
#   tval     value returned when the RCPL is in the range
#   fval     value returned when the RCPL is not in the range
#
def ifRcplInRange(d, first, last=None, tval="", fval=""):
    rcpl = int(d.getVar("WRLINUX_UPDATE_VERSION"))
    return tval if rcpl >= first and (last is None or rcpl <= last) else fval

python() {
    # get a dictionary of flags and quit if there aren't any
    #
    flags = d.getVarFlags("SRC_URI_APPEND_RCPL")
    if not flags:
        return
        
    current_rcpl = int(d.getVar("WRLINUX_UPDATE_VERSION"))
    
    # process the dictionary entries
    # the keys are of the form "m" or "m-n"
    #
    for i in flags.keys():
        range = i.split("-")
        first = int(range[0])
        # assume "m-n"
        try:
            last = int(range[1])
        # "m" meaning "m only"
        except IndexError:
            last = first
        # "m-" meaning "m and above"
        except ValueError:
            last = current_rcpl
    
        if current_rcpl >= first and current_rcpl <= last:
             d.appendVar('SRC_URI', " "+flags[i])

}
