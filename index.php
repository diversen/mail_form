<?php


//include_once "lib/captcha.php";

if (!isset($_SESSION['referer'])){
    $_SESSION['referer'] = $_SERVER['HTTP_REFERER'];
}

if (isset($_POST['submit'])){
    mailForm::validateMailForm();
    if (empty(mailForm::$errors)){
        $res = mailForm::sendMail();
        if ($res){
            session::setActionMessage(lang::translate('mail_form_sent'));
            if (isset($_SESSION['referer'])){
                $header = "Location: $_SESSION[referer]";
                header($header);
            } else {
                return;
            }
        }
    } else {
        view_form_errors(mailForm::$errors);
    }
}

mailForm::viewMailForm();