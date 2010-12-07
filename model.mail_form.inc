<?php

class mailForm {

    static public $errors = array();

    public static function validateMailForm (){
        $_POST = cos_htmlspecialchars($_POST);
        if (@isset($_POST['submit'])){
            
            if (!cosValidate::validateEmailAndDomain($_POST['email'])){
                self::$errors[] = lang::translate('mail_form_error_email');
            }
            if (@empty($_POST['title'])){
                self::$errors[] = lang::translate('mail_form_error_title');
            }
            if (@empty($_POST['content'])){
                self::$errors[] = lang::translate('mail_form_error_content');
            }
            if (!captcha::checkCaptcha($_POST['captcha'])){
                self::$errors[] = lang::translate('mail_form_error_captcha');
            }
        }        
    }

    public static function viewMailForm (){
        include _COS_PATH . "/modules/mail_form/views/form.php";
    }

    public static function sendMail (){

        $from = get_main_ini('site_email');
        $title = $_POST['title'];
        $content = $_POST['content'];
        $to = get_module_ini('mail_form_send_to');
        $reply_to = $_POST['email'];
        
        $res = mail_utf8(
            $to,
            $title,
            $content,
            $from, $reply_to);
        return $res;
    }

}