<?php

$_INSTALL['VERSION'] = 1.71;

$_INSTALL['PUBLIC_CLONE_URL'] = 'git://github.com/diversen/mail_form.git';
$_INSTALL['PRIVATE_CLONE_URL'] = 'git@github.com:diversen/mail_form.git';

if (config::getModuleIni('mail_form_main_menu')) {

    $_INSTALL['MAIN_MENU_ITEM'] = array (
        'title' => 'mail_form_main_menu',
        'url' => '/mail_form/index',
        'module_name' => 'mail_form',
        'parent' => 0,
        'weight' => 2,
    );
}
