package com.stu.util;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Tools {

    public static boolean isNumeric(String str) {
        Pattern pattern = Pattern.compile("[0-9]*");
        Matcher matcher = pattern.matcher(str);
        if (!matcher.matches()) {
            return false;
        }
        return true;
    }

}
