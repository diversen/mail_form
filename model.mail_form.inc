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
                self::$errors[] = lang::translate('Not a correct email');
            }
            if (@empty($_POST['title'])){
                self::$errors[] = lang::translate('Enter title');
            }
            if (@empty($_POST['content'])){
                self::$errors[] = lang::translate('Enter content');
            }
            if (config::getModuleIni('mail_form_captcha')) {
                if (!captcha::checkCaptcha($_POST['captcha'])){
                    self::$errors[] = lang::translate('Not a correct calculation of captcha');
                }
            }
        }        
    }

    /**
     * send email
     * @return boolean $res 
     */
    public static function sendMail (){

        $from = config::getMainIni('site_email');

        $title = $_POST['title'];
        $content = $_POST['content'];
        $to = config::getMainIni('site_email');
        
        if (config::getModuleIni('mail_form_send_to')) {
            $to = config::getModuleIni('mail_form_send_to');
        } else {
            $to = config::getMainIni('site_email');
        }

        $reply_to = $_POST['email'];
        $res = cosMail::text(
            $to,
            $title,
            $content,
            $from, 
            $reply_to);
        return $res;
    }
}
