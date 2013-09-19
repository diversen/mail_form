<?php


http::prg();

if (!isset($_SESSION['referer'])){
    $_SESSION['referer'] = @$_SERVER['HTTP_REFERER'];
}

if (isset($_GET['sent']) && $_GET['sent'] == 'true') {
    $res = 1;
} else {
    $res = null;
}

if (isset($_POST['mail_form_submit'])){
    mailForm::validateMailForm();
    if (empty(mailForm::$errors)){
        $res = mailForm::sendMail();
        if ($res){
            session::setActionMessage(lang::translate('Fill out the contact form'));
            http::locationHeader('/mail_form/index?sent=true');
        }
    }
}

if (!$res) {
    $vars = array ();
    $vars['errors'] = mailForm::$errors;
    echo view::get('mail_form', 'form', $vars);
} else {
    echo view::get('mail_form', 'sent', array ());
}