<?php

include_once "coslib/captcha.php";

class mailForm {

    static public $errors = array();

    /**
     * validate form 
     */
    public static function validateMailForm (){
        $_POST = html::specialEncode($_POST);

        if (@isset($_POST['mail_form_submit'])){
            
            if (!cosValidate::validateEmailAndDomain($_POST['email'])){
                self::$errors[] = lang::translate('mail_form_error_email');
            }
            if (@empty($_POST['title'])){
                self::$errors[] = lang::translate('mail_form_error_title');
            }
            if (@empty($_POST['content'])){
                self::$errors[] = lang::translate('mail_form_error_content');
            }
            if (config::getModuleIni('mail_form_captcha')) {
                if (!captcha::checkCaptcha($_POST['captcha'])){
                    self::$errors[] = lang::translate('mail_form_error_captcha');
                }
            }
        }        
    }

    /**
     * send email
     * @return boolean $res 
     */
    public static function sendMail (){

        $from = get_main_ini('site_email');

        $title = $_POST['title'];
        $content = $_POST['content'];
        $to = get_main_ini('site_email');
        
        if (config::getModuleIni('mail_form_send_to')) {
            $to = config::getModuleIni('mail_form_send_to');
        } else {
            $to = get_main_ini('site_email');
        }

        $reply_to = $_POST['email'];
        $res = mail_utf8(
            $to,
            $title,
            $content,
            $from, $reply_to);
        return $res;
    }
}
